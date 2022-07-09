#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)
using ld = long double;

ld x[5], y[5];
ld dis(ld a, ld b, ld c, ld d){
    return (a - b)*(a - b) + (c-d)*(c-d);
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    rep(i, 0, 3){
        cin >> x[i] >> y[i];
    }
    x[3] = x[1];
    y[3] = y[2];
    x[4] = x[2];
    y[4] = y[1];

    ld ans = 1e9;
    rep(i, 1, 5){
        // cout << x[i] << ' ' << y[i] << '\n'; 
        ans = min(ans, sqrt(dis(x[0], x[i], y[0], y[i])));
    }
    if(x[1] < x[0] && x[0] < x[2]){
        ans = min(ans, abs(y[0] - y[1]));
        ans = min(ans, abs(y[0] - y[2]));
    }
    if(y[1] < y[0] && y[0] < y[2]){
        ans = min(ans, abs(x[0] - x[1]));
        ans = min(ans, abs(x[0] - x[2]));

    }
    cout << fixed << setprecision(3) << ans << '\n';

    return 0;
}