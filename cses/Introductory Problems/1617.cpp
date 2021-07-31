#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MOD = 1000000007;
int n;
ll ans = 1, b = 2;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    while(n){
        if(n & 1){
            ans *= b, ans %= MOD;
        }
        b *= b, b %= MOD;
        n >>= 1;
    }
    cout << ans << '\n';
    return 0;
}