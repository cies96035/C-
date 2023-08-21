#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 1e2 + 5;
int n, a;
int dp[3][MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    rep(i, 0, n){
        cin >> a;
        dp[0][i + 1] = max(dp[0][i], max(dp[1][i], dp[2][i]));
        if(a & 1)
            dp[1][i + 1] = max(dp[0][i], dp[2][i]) + 1;
        if(a > 1)
            dp[2][i + 1] = max(dp[0][i], dp[1][i]) + 1;
    }
    cout << n - max(dp[0][n], max(dp[1][n], dp[2][n])) << '\n';
    return 0;
}