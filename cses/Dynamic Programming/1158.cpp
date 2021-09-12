#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 1e3 + 5;
const int MAX_X = 1e5 + 5;
int n, x;
pii book[MAX_N];
int dp[MAX_X];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> x;
    rep(i, 0, n){
        cin >> book[i].first;
    }
    rep(i, 0, n){
        cin >> book[i].second;
    }
    rep(i, 0, n){
        rvep(j, x, book[i].first){
            dp[j] = max(dp[j - book[i].first] + book[i].second, dp[j]);
        }
    }
    cout << dp[x] << '\n';
    return 0;
}