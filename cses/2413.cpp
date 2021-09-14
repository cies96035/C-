#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 1e6 + 5;
int dp[MAX_N][2];
int t, n, cnt, cnt2;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cnt2 = cnt = dp[0][0] = 1;
    rep(i, 0, 10){
        dp[i + 1][0] += cnt;
        cnt += dp[i + 1][0];
        cout << dp[i + 1][0] << endl;
    }
    cin >> t;
    while(t--){
        cin >> n;
    }
    return 0;
}