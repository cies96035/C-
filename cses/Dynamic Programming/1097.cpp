#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 5e3 + 5;
int n;
pair<bool, ll> dp[MAX_N][MAX_N];
ll arr[MAX_N];
ll preSum[MAX_N];
ll getans(int a, int b){
    if(a == b){
        return 0;
    }else if(dp[a][b].first){
        return dp[a][b].second;
    }

    dp[a][b].first = true;
    return dp[a][b].second = max(
        preSum[b] - preSum[a] - getans(a + 1, b),
        preSum[b] - preSum[a] - getans(a, b - 1)
    );
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    rep(i, 0, n){
        cin >> arr[i];
        preSum[i + 1] = preSum[i] + arr[i];
    }
    cout << getans(0, n) << '\n';
    return 0;
}