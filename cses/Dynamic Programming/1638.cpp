#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MOD = 1e9 + 7;
const int MAX_N = 1e3 + 5;

ll n, dp[MAX_N];
char grid;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    dp[0] = 1;
    rep(i, 0, n){
        cin >> grid;
        if(grid == '*'){
            dp[0] = 0;
        }
        rep(j, 1, n){
            cin >> grid;
            if(grid == '*'){
                dp[j] = 0;
            }else{
                dp[j] += dp[j - 1], dp[j] %= MOD;
            }
        }
    }
    cout << dp[n - 1] << '\n';
    return 0;
}