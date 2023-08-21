#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

int n, m;
pll trans2D(int Idx){
    return {Idx / m, Idx % m};
}
pll moveUp(pll point){
    point.first++;
    return point;
}
pll moveRight(pll point){
    point.second++;
    return point;
}
void fail(){
    cin >> n >> m;
    n++, m++;
    int r, t, d, coord;
    vector<tuple<int, int, int>> rail;
    cin >> r;
    rep(i, 0, r){
        cin >> t >> d >> coord;
        rail.push_back({t, d - 1, coord});
    }
    set<pll> vis;
    queue<pll> points;
    priority_queue<pll, vector<pll>, greater<pll>> togo;
    togo.push({0, 0});
    while(!togo.empty()){
        pll cur = trans2D(togo.top().second);
        int val = togo.top().first;
        togo.pop();
        cout <<cur.first << ' ' << cur.second << endl;
        cout << val << endl;
        if(vis.count(cur)) continue;
        vis.insert(cur);
        if(cur == pll{n - 1, m - 1}){
            cout << val << '\n';
            return;
        }

        pll points[3] = {cur, moveRight(cur), moveUp(cur)};
        set<int> deadTime[3];
        rep(i, 0, r){
            rep(j, 0, 3){
                if(get<1>(rail[i])){ // vertical
                    if(get<2>(rail[i]) == points[j].second){
                        deadTime[j].insert(get<0>(rail[i]));
                    }
                }else{ // horizon
                    if(get<2>(rail[i]) == points[j].first){
                        deadTime[j].insert(get<0>(rail[i]));
                    }
                }
            }
        }
        // right
        if(points[1].second < m){
            int T = val;
            while(true){
                T++;
                if(deadTime[0].count(T) && deadTime[1].count(T)){
                    break;
                }else if(!deadTime[1].count(T)){
                    togo.push({T, points[1].first * m + points[1].second});
                    break;
                }
            }
        }

        // up
        if(points[2].first < n){
            int T = val;
            while(true){
                T++;
                if(deadTime[0].count(T) && deadTime[2].count(T)){
                    break;
                }else if(!deadTime[2].count(T)){
                    togo.push({T, points[2].first * m + points[2].second});
                    break;
                }
            }
        }
    }
    cout << "-1\n";
    
}
void f(){
    cin >> n >> m;
    n++, m++;
    int r, t, d, coord;
    vector<tuple<int, int, int>> rail;
    cin >> r;
    rep(i, 0, r){
        cin >> t >> d >> coord;
        rail.push_back({t, d - 1, coord});
    }

}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while(t--) f();
    
    return 0;
}