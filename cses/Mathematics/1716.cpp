#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MOD = 1000000007;
ll n, m;

ll qpow(ll a, int b){
    ll ans = 1;
    while(b){
        if(b & 1){
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ll ans = 1;
    cin >> n >> m;
    n += m;
    rep(i, 1, n){
        ans = ans * i % MOD;
        if(i < n - m){
            ans = ans * qpow(i, MOD - 2) % MOD;
        }
        if(i <= m){
            ans = ans * qpow(i, MOD - 2) % MOD;
        }
    }
    cout << ans << '\n';
    return 0;
}