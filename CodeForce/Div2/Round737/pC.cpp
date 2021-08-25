#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_NK = 2e5 + 5;
const int MOD = 1e9 + 7;
int t;
ll n, k;
ll DPa[MAX_NK], DPb[MAX_NK];
ll inv[MAX_NK], finv[MAX_NK], f[MAX_NK];
ll oo, oz, zz;
ll qpow(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1){
            ans *= a; ans %= MOD;
        }
        a *= a; a %= MOD;
        b >>= 1;
    }
    return ans;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    inv[1] = 1;
    rep(i, 2, MAX_NK){
        inv[i] = qpow(i, MOD - 2);
    }
    finv[0] = finv[1] = 1;
    f[0] = f[1] = 1;
    rep(i, 2, MAX_NK){
        f[i] = i * f[i - 1];
        f[i] %= MOD;
        finv[i] = inv[i] * finv[i - 1];
        finv[i] %= MOD;
    }
    cin >> t;
    while(t--){
        cin >> n >> k;
        if(k == 0){
            cout << "1\n";
        }else{
            oo = (n & 1 ? 1 : 0);
            oz = 1 - oo;
            zz = 0;
            for(int i = 0; i < n; i += 2){
                zz += (f[n] * finv[n - i]) % MOD * finv[i];
                zz %= MOD;
            }
            // cout << oo << ' ' << oz << ' ' << zz << endl;
            DPa[0] = 0;
            DPb[0] = 1;
            rep(i, 0, k){
                DPa[i + 1] = qpow(2, n) * DPa[i] % MOD;
                DPa[i + 1] += DPb[i] * oz; DPa[i + 1] %= MOD;
                DPb[i + 1] = (oo + zz) * DPb[i] % MOD;
            }
            cout << (DPa[k] + DPb[k]) % MOD << '\n';
        }
    }
    return 0;
}