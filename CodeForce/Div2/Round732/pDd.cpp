#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const ll MOD = 998244353;
int n;
ll qpow(ll a, ll b){
    ll base = 1;
    while( b ){
        if( b % 2 ){
            base *= a;
            base %= MOD;
        }
        a *= a;
        a %= MOD;
        b /= 2;
    }
    return base;
}
ll C(ll n, ll m){
    ll ans = 1;
    for(int i = 1; i <= m; i++){
        ans *= n - i + 1;
        ans %= MOD;
        ans *= qpow(i, MOD - 2);
        ans %= MOD;
    }
    return ans;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t;
    string str;
    int Zero, OOne;
    bool one;

    cin >> t;
    while(t--){
        Zero = OOne = 0;
        one = false;
        cin >> n;
        cin >> str;
        for(auto c : str){
            if(c == '1'){
                if(one){
                    one = false;
                    OOne++;
                }else{
                    one = true;
                }
            }else{
                one = false;
                Zero++;
            }
        }
        cout << C(OOne + Zero, OOne) << '\n';
    }
    return 0;
}