#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 3e3 + 5;
const ll INF = 0xffffffff;
ll dp[MAX_N][MAX_N];
ll a[MAX_N], b[MAX_N];
ll mx[4][MAX_N];
const int w[4][2] ={
    {1, -1}, {1, 1}, {-1, -1}, {-1, 1}
};
void f(){
    int n, k;
    
    cin >> n >> k;
    rrep(i, 1, n){
        cin >> a[i];
    }
    rrep(i, 1, n){
        cin >> b[i];
    }
    
    rrep(i, 0, n){
        rrep(j, 0, k) {
            dp[i][j] = 0;
        }
        rep(j, 0, 4){
            mx[j][i] = -INF;
        }
    }
    
    rrep(i, 1, n){
        rrep(j, 1, min(i, k)){ 
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            rep(kk, 0, 4){
                mx[kk][i - j] = max(mx[kk][i - j], dp[i - 1][j - 1] + a[i] * w[kk][0] + b[i] * w[kk][1]);
            }
            rep(kk, 0, 4){
                dp[i][j] = max(dp[i][j], mx[kk][i - j] + b[i] * w[3 - kk][0] + a[i] * w[3 - kk][1]);
            }
        }
    }
    cout << dp[n][k] << '\n';
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while(t--) f();
    
    return 0;
}