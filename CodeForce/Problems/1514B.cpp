#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MOD = 1000000007;
int qpow(ll n, ll k){
    ll ans = 1;
    while(k){
        if(k & 1){
            ans *= n;
            ans %= MOD;
        }
        n *= n;
        n %= MOD;
        k >>= 1;
    }
    return ans;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t, n, k;

    cin >> t;
    while(t--){
        cin >> n >> k;
        cout << qpow(n, k) << '\n';
    }
    return 0;
}