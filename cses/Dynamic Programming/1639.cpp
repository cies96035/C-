#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_S = 5e3 + 5;
string n, m;
int dp[MAX_S][MAX_S];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    rrep(i, 1, n.size()){
        dp[i][0] = i;
    }
    rrep(i, 1, m.size()){
        dp[0][i] = i;
    }
    rep(i, 0, n.size()){
        rep(j, 0, m.size()){
            dp[i + 1][j + 1] = min(
                min(dp[i + 1][j], dp[i][j + 1]) + 1,
                dp[i][j] + (n[i] != m[j])
            );
        }
    }
    cout << dp[n.size()][m.size()] << '\n';
    return 0;
}