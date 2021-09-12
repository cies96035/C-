#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)

const int MOD = 1e9 + 7;
const int MAX_X = 1e6 + 5;
const int MAX_N = 1e2 + 5;
int n, x;
int c[MAX_N];
ll dp[MAX_X];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> x;
    rep(i, 0, n){
        cin >> c[i];
    }
    sort(c, c + n);
    dp[0] = 1;
    rrep(i, 1, x){
        rep(j, 0, n){
            if(c[j] > i){
                continue;
            }
            dp[i] += dp[i - c[j]];
        }
        dp[i] %= MOD;
    }
    cout << dp[x] << '\n';
    return 0;
}