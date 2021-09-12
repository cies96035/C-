#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const ll MOD = 1000000007;
ll qpow(ll a, ll b, const ll m){
    ll ans = 1;
    while(b){
        if(b & 1){
            ans = ans * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}
ll n;
ll a, b, c;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << qpow(2, MOD - 2, MOD) << endl;
    cin >> n;
    while(n--){
        cin >> a >> b >> c;
        cout << qpow(a, qpow(b, c, MOD - 1), MOD) << '\n';
    }
    
    return 0;
}