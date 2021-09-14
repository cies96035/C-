#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_S = 5e2 + 5;
const int INF = 0x3fffffff;
int dp[MAX_S][MAX_S];

int getAns(int x, int y){
    if(dp[x][y] != -1){
        return dp[x][y];
    }else if(x == y){
        return dp[x][y] = 0;
    }
    dp[x][y] = INF;
    rvep(i, (x >> 1), 1){
        dp[x][y] = min(dp[x][y], getAns(i, y) + getAns(x - i, y) + 1);
    }
    rvep(i, (y >> 1), 1){
        dp[x][y] = min(dp[x][y], getAns(x, i) + getAns(x, y - i) + 1);
    }
    return dp[x][y];
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    memset(dp, -1, sizeof(dp));
    int x, y;
    cin >> x >> y;
    cout << getAns(x, y) << '\n';
    return 0;
}