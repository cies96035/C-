#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 5e2 + 5;
const int MAX_NS = 2e5 + 5;
const int MOD = 1e9 + 7;
ll n, a[MAX_N], dp[MAX_NS];
ll sum;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    sum = n * (n + 1) >> 1;
    if(sum & 1){
        cout << 0 << '\n';
    }else{
        sum >>= 1;
        dp[0] = 1;
        rep(i, 0, n){
            rvep(j, sum, i){
                dp[j] += dp[j - i];
                if(dp[j] >= MOD){
                    dp[j] -= MOD;
                }
            }
        }
        cout << ( dp[sum] * 500000004 ) % MOD << '\n';
    }
    return 0;
}