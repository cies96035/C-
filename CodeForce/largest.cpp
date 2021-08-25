#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define x first
#define y second
using Point = pair<ll, ll>;
using Poly = vector<Point>;

const int MAX_N = 1e4;
ll cross(Point p1, Point p2, Point p3) {
    return (p1.x - p2.x) * (p3.y - p2.y) - (p1.y - p2.y) * (p3.x - p2.x);
}

Poly convexHull(Poly& poly) {
    ll l = 0, r = 0;
    Poly lc, rc;

    for (Point p : poly) {
        while (l > 1 && cross(lc[l - 2], lc[l - 1], p) <= 0)
            lc.pop_back(), --l;
        while (r > 1 && cross(rc[r - 2], rc[r - 1], p) >= 0)
            rc.pop_back(), --r;
        
        lc.emplace_back(p); ++l;
        rc.emplace_back(p); ++r;
    }

    lc.pop_back();
    reverse(rc.begin(), rc.end());
    rc.pop_back();
    for (Point p : rc)
        lc.emplace_back(p);

    return lc;
}

int nn;
inline int next(int a){
    return (a + 1) % nn;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll N;
    Poly a;
    cin >> N;
    rep(i, 0, N){
        Point ipt;
        ipt.x = i;
        cin >> ipt.y;
        a.emplace_back(ipt);
    }
    Poly cH = convexHull(a);
    nn = cH.size();
    pair<ll, Poly> ans;
    ans.first = 0;
    ans.second = {{0, 0}, {1, 1}, {2, 2}};
    for(int i = 0; i < cH.size(); i++){
        for(int j = next(i), k = j; next(j) != i; j = next(j)){
            pair<ll, Poly> b = { abs( cross(cH[i], cH[j], cH[k]) ), {cH[i], cH[j], cH[k]} };
            while(next(k) != i){
                ll c = abs( cross(cH[i], cH[j], cH[next(k)]) );
                if(c < b.first) break;
                b.first = c;
                k = next(k);
                b.second = {cH[i], cH[j], cH[k]};
            }
            if(b.first > ans.first){
                ans = b;
            }
        }
    }
    sort(ans.second.begin(), ans.second.end());
    cout << ans.first << '\n' << ans.second[0].x + 1;
    rep(i, 1, 3){
        cout << ' ' << ans.second[i].x + 1;
    }
    cout << '\n';
    return 0;
}