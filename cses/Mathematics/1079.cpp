#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MOD = 1000000007;
const int MAX_NUM = 1000005;
int n;
int a, b;
int qpow(ll a, int b){
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
ll Factorial[MAX_NUM];
ll Fmodinv[MAX_NUM];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    Factorial[0] = Fmodinv[0] = 1;
    for(int i = 1; i < MAX_NUM; i++){
        Fmodinv[i] = Fmodinv[i - 1] * qpow(i, MOD - 2) % MOD;
        Factorial[i] = Factorial[i - 1] * i % MOD;
    }
    
    cin >> n;
    while(n--){
        cin >> a >> b;
        cout << (Factorial[a] * Fmodinv[b] % MOD) * Fmodinv[a - b] % MOD << '\n';
    }
    return 0;
}