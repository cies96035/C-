#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)


const int MAX_N = 2e5 + 10;
vector<pll> e[MAX_N];
ll pos[MAX_N];
bool vis[MAX_N];
bool flg;
void dfs(int x){
    if(vis[x] || !flg) return;
    vis[x] = true;
    for(auto i: e[x]){
        ll nxpos = pos[x] + i.second;
        if(vis[i.first] && pos[i.first] != nxpos){
            flg = false;
        }else{
            pos[i.first] = nxpos;
            dfs(i.first);
        }
    }
}
void f(){
    flg = true;
    int n, m;
    cin >> n >> m;
    rrep(i, 1, n){
        vis[i] = false;
        e[i].clear();
    }
    int a, b, d;
    rep(i, 0, m){
        cin >> a >> b >> d;
        e[a].push_back({b, d});
        e[b].push_back({a, -d});
    }
    rrep(i, 1, n){
        pos[i] = 0;
        dfs(i);
    }
    if(flg){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
    // cout << flush;
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