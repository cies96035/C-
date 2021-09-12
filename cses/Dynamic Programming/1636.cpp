#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)

const int MAX_X = 1e6 + 5;
const int MAX_N = 1e2 + 5;
const int MOD = 1e9 + 7;

int n, x;
int dp[MAX_X], c[MAX_N];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> x;
    rep(i, 0, n){
        cin >> c[i];
    }

    dp[0] = 1;
    rep(i, 0, n){
        rrep(j, c[i], x){
            if(dp[j - c[i]]){
                dp[j] += dp[j - c[i]], dp[j] %= MOD;
            }
        }
    }
    cout << dp[x] << '\n';
    return 0;
}