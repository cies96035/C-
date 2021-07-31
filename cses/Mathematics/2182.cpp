#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const ll MOD = 1e9 + 7;
const int MAX_N = 1000005;
ll n, x[MAX_N], k[MAX_N];
ll number, sum, product, num, Pow;
bool flg;
int qpow(ll a, ll b){
    ll ans = 1;
    while(b){
        if( b & 1 ){
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
    
    sum = number = product = num = Pow = 1;
    cin >> n;
    rep(i, 0, n){
        cin >> x[i] >> k[i];
        number = number * (k[i] + 1) % MOD;
        sum = sum
            * ( qpow(x[i], k[i] + 1) - 1 ) % MOD
            * qpow(x[i] - 1, MOD - 2) % MOD;
        if(k[i] & 1){
            flg = true;
        }
    }
    cout << number << ' ' << sum << ' ';
    if(flg){ //case 1 : normal number
        rep(i, 0, n){
            if(k[i] & 1 && flg){
                Pow = Pow * ( (k[i] + 1) >> 1 ) % (MOD - 1);
                flg = false;
            }else{
                Pow = Pow * (k[i] + 1) % (MOD - 1);
            }
            num = num * qpow(x[i], k[i]) % MOD;
        }
        product = qpow(num, Pow) % MOD;
    }else{ //case 2 : a square number
        rep(i, 0, n){
            Pow = Pow * (k[i] + 1) % (MOD - 1);
            num = num * qpow(x[i], k[i] >> 1) % MOD;
        }
        product = qpow(num, Pow) % MOD;
    }
    cout << product << '\n';

    return 0;
}