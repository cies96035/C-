#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 10;
int dpMin[MAX_N];
int dpMax[MAX_N];
pair<int,int> dp[MAX_N];
int idx;

void f(){
    idx = 1;
    dpMin[1] = 0;
    dpMax[1] = 1;
    dp[1] = {0, 1};
    char op;
    int n;
    cin >> n;
    int a, b, c;
    rep(i, 0, n){
        cin >> op;
        if(op == '+'){
            cin >> a >> b;
            dp[++idx].first = dp[a].first + b;
            dp[idx].second = dp[a].second + b;
            if(dp[idx].first > 0)dp[idx].first = 0;
            if(dp[idx].second < 0)dp[idx].second = 0;
            dpMin[idx] = min(dpMin[a], dp[idx].first);
            dpMax[idx] = max(dpMax[a], dp[idx].second);
        }else{
            cin >> a >> b >> c;
            // cout << dpMin[b] << ' ' << dpMax[b] << endl;
            if(dpMin[b] <= c && c <= dpMax[b]){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--){
        f();
    }
    return 0;
}