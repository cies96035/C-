#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

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
    
    return 0;
}