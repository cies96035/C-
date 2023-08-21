#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 1e5 + 5;
int t;
int n, a, b;
int u, v, w;
bool flg;
vector<pll> e[MAX_N];
set<int> s;
int vis[MAX_N];
void dfs(int x, int val){
    if(vis[x] == 1){
        return;
    }
    if(x == b){
        return;
    }
    s.insert(val);
    vis[x] = 1;
    for(auto i : e[x]){
        dfs(i.first, val^i.second);
    }
}
void dfs2(int x, int val){
    if(vis[x] == 2){
        return;
    }
    if(x != b){
        if(s.count(val)){
            flg = true;
        }
    }
    vis[x] = 2;
    for(auto i : e[x]){
        dfs2(i.first, val^i.second);
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        flg = false;
        cin >> n >> a >> b;
        rrep(i, 1, n){
            e[i].clear();
            vis[i] = 0;
        }
        s.clear();
        rep(i, 1, n){
            cin >> u >> v >> w;
            e[u].push_back({v, w});
            e[v].push_back({u, w});
        }
        dfs(a, 0);
        dfs2(b, 0);
        if(flg){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
    return 0;
}