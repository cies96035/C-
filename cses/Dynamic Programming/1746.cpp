#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 1e5 + 5;
const int MAX_M = 1e2 + 5;
const int MOD = 1e9 + 7;
int n, m, x;
ll dp[MAX_N][MAX_M];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    for(int i = 1; i < MAX_M ; i += 3){
        dp[0][i] = 1;
    }
    rrep(i, 1, n){
        cin >> x;
        if(x == 0){
            rrep(j, 1, m){
                dp[i][j] = 
                dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1];
                dp[i][j] %= MOD;
            }
        }else{
            dp[i][x] = 
            dp[i - 1][x - 1] + dp[i - 1][x] + dp[i - 1][x + 1];
            dp[i][x] %= MOD;
        }
    }
    if(x == 0){
        rrep(i, 1, m){
            dp[n][0] += dp[n][i];
        }
        cout << dp[n][0] % MOD<< '\n';
    }else{
        cout << dp[n][x] << '\n';
    }
    return 0;
}