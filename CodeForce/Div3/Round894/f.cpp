#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 5;
ll s[MAX_N];
ll w, f, n;
ll total;
bool dp[1000005];
void F(){
    cin >> w >> f >> n;
    total = 0;
    rep(i, 0, n){
        cin >> s[i];
        // if(i <= 13){
        //     s[i] = 1 << i;
        // }else{
        //     s[i] = i;
        // }
        total += s[i];
    }
    int htotal = total / 2;
    rrep(i, 1, htotal) dp[i] = 0;
    dp[0] = 1;
    rep(i, 0, n){
        rvep(j, htotal, s[i]){
            dp[j] += dp[j - s[i]];
        }
    }
    
    ll ans = 0x3fffffff;
    rrep(c, 0, htotal){
        if(dp[c]){
            ans = min(ans, max((c + w - 1) / w, (total - c + f - 1) / f));
            ans = min(ans, max((total - c + w - 1) / w, (c + f - 1) / f));
        }
    }
    cout << ans << '\n';
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while(t--) F();
    
    return 0;
}