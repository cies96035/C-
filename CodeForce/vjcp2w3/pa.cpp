#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;


#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)
#define X first
#define Y second

const ll LARGE = 2e9 + 100;

int n, m;
inline void linertrans(pll &p){ //no two diff point in the same x
    p = {LARGE * p.X + p.Y, LARGE * p.Y + p.X};
}

struct EDGE{
    // start point, end point
    pll s, e;
    EDGE(pll x, pll y){
        linertrans(x), linertrans(y);
        s = x, e = y;
        if(s.X > e.X){
            swap(s, e);
        }
    }
};

inline ll f1(const EDGE &edge, pll p){
    __int128 a = edge.s.Y - edge.e.Y, b = p.X - edge.s.X, c = edge.s.X - edge.e.X, d = p.Y - edge.s.Y;
    __int128 e = a * b, f = c * d;
	return e == f ? 0 : (e > f ? 1 : -1);
    // return (edge.s.Y - edge.e.Y) * (p.X - edge.s.X) - (edge.s.X - edge.e.X) * (p.Y - edge.s.Y);
}

// return true p is above edge (include)
int cmp1(const EDGE &edge, const pll &p){
    /*
    line e : (s.y-e.y)/(s.x-e.x) * (x-s.x) = (y-s.y)
    -> (s.y-e.y) * (x-s.x) = (s.x-e.x) * (y-s.y)
    -> (s.y-e.y) * (x-s.x) - (s.x-e.x) * (y-s.y) = 0
    -> f(x,y) = ax + by + c = 0
    point p and q same side ->  f(p) * f(q) > 0
    */
    pll q = edge.s;
    q.Y++;

    return f1(edge, p) == 0 ? 2 : !( (f1(edge, p) > 0) ^ (f1(edge, q) > 0) );
}

//compare two edge, if x is above y, return true
struct cmp2{
    bool operator()(const EDGE &x, const EDGE &y){
        if(x.s == y.s){
            return x.e.Y > y.e.Y;
        }else if(x.e == y.e){
            return x.s.Y > y.s.Y;
        }else if(y.s.X < x.s.X && x.s.X < y.e.X){
            return cmp1(y, x.s);
        }else{
            return cmp1(y, x.e);
        }
    }
};
typedef tree<EDGE, null_type, cmp2, rb_tree_tag, tree_order_statistics_node_update> EDGE_set;

EDGE_set sete;
int findabove(pll p){
    if(sete.empty()){
        return 0;
    }
    int l = 0, r = sete.size(), mid;
    while(l < r){
        mid = (l + r) >> 1;
        int t = cmp1(*sete.find_by_order(mid), p);
        if(t == 2){
            return 1;
        }
        if(t){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    return l;
}

// for debug
inline void outputpoint(pll x, string s, string ss){
    cout << s << " : (" << x.X << ", " << x.Y << ')' << ss;
    cout << flush;
}
inline void outputline(EDGE edge){
    outputpoint(edge.s, "s", ", "); outputpoint(edge.e, "e", "\n");
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    vector<EDGE> ve;
    vector<tuple<ll, ll, ll>> timestamp;
    set<ll> sep;

    cin >> n >> m;

    ll x, y, fx, fy, xed, yed;

    cin >> fx >> fy;
    xed = fx, yed = fy;
    rep(i, 0, n - 1){
        cin >> x >> y;

        ve.push_back(EDGE{{x, y},{xed, yed}});
        sep.insert(ve.back().s.X), sep.insert(ve.back().e.X);
        timestamp.push_back({ve.back().s.X, 0, i}), timestamp.push_back({ve.back().e.X, -1, i});

        xed = x, yed = y;
    }

    ve.push_back(EDGE{{x, y},{fx, fy}});
    sep.insert(ve.back().s.X), sep.insert(ve.back().e.X);
    timestamp.push_back({ve.back().s.X, 0, n - 1}), timestamp.push_back({ve.back().e.X, -1, n - 1});

    vector<pll> Points(m);
    vector<bool> ans(m);

    rep(i, 0, m){
        cin >> x >> y;
        Points[i] = {x, y};
        linertrans(Points[i]);
        timestamp.push_back({Points[i].X, 1, i});
    }

    sort(timestamp.begin(), timestamp.end());

    for(auto ts : timestamp){
        if(get<1>(ts) == -1){
            sete.erase(ve[get<2>(ts)]);
        }else if(get<1>(ts) == 0){
            sete.insert(ve[get<2>(ts)]);
        }else{
            if(sep.count(get<0>(ts))){ // on one edge's end
                ans[get<2>(ts)] = true;
            }else{ // find number of edge below point (or 1 if point on edge)
                ans[get<2>(ts)] = findabove(Points[get<2>(ts)]) & 1;
            }
        }
    }
    
    for(int i = 0; i < m; i++){
        if(ans[i]){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}
/*

3 3
0 0
5 5
5 0
1 1
1 2
2 1


4 4
0 0
1 1
2 0
1 5
1 0
1 1
1 2
1 3


4 10
1 1
1 -1
-1 -1
-1 1
-1 -1
-1 0
-1 1
0 -1
0 0
0 1
1 -1
1 0
1 1
2 2
*/