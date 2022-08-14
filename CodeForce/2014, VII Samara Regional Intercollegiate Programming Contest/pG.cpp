#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

ll r;
pair<ld, ld> p[3];
ld dis(ld a, ld b, ld c, ld d){
    return (a - c) * (a - c) + (b - d) * (b - d);
}
bool check(ll i, ll j){
    ld px = (p[i].first + p[j].first) / 2;
    ld py = (p[i].second + p[j].second) / 2;
    rep(k, 0, 3){
        if(sqrt(dis(px, py, p[k].first, p[k].second)) > r + 5e-4){
            return false;
        }
    }
    cout << "YES\n";
    cout << fixed << setprecision(6) << px << ' ' << py << '\n';
    return true;

}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> r;
    rep(i, 0, 3){
        cin >> p[i].first >> p[i].second;
    }
    pll m[3] = {{0, 1}, {0, 2}, {1, 2}};
    bool flg = false;
    rep(i, 0, 3){
        if(check(m[i].first, m[i].second)){
            flg = true;
            break;
        }
    }
    if(!flg) cout << "NO\n";
    
    return 0;
}