#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 5;
vector<int> e[MAX_N];
ll dp[MAX_N];
void dfs(int x, int par){
    if(dp[x] != 0) return;
    if(e[x].size() == 1 && x != 1){
        dp[x] = 1;
        return;
    }
    for(auto i: e[x]){
        if(i != par){
            dfs(i, x);
            dp[x] += dp[i];
        }
    }
}
void f(){
    int n;
    cin >> n;
    int u, v;
    rep(i, 1, n){
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    int q;
    cin >> q;
    rep(i, 0, q){
        cin >> u >> v;
        cout << dp[u] * dp[v] << '\n';
    }
    rrep(i, 1, n){
        dp[i] = 0;
        e[i].clear();
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