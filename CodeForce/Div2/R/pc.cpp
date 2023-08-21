#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)

const int MAX_N = 2e5 + 5;
const ll MOD = 998244353;
int t, n, ipt;
ll fact(int x){
    ll ans = 1;
    rrep(i, 2, x){
        ans *= i;
        ans %= MOD;
    }
    return ans;
}
ll qpow(ll b, ll n, ll m){ //base ^ n % M
    ll ans = 1;
    while(n){
        if(n & 1){
            ans *= b, ans %= m;
        }
        b *= b, b %= m;
        n >>= 1;
    }
    return ans;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        map<int, int> s;
        cin >> n;
        rep(i, 0, n){
            cin >> ipt;
            s[ipt]++;
        }
        bool flg = true;
        if((--s.end())->second >= 2){
            cout << fact(n) << '\n';
        }else if(s.size() > 1 && (--s.end())->first != (--(--s.end()))->first + 1){
            cout << "0\n";
        }else{
            cout << (MOD + fact(n) - (fact(n) * qpow( (--(--s.end()))->second + 1, MOD - 2, MOD )) % MOD ) % MOD << '\n';
        }
    }
    return 0;
}