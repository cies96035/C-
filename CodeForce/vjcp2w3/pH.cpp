#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0)
#define int ll
#define pb emplace_back
#define f0r(i, b) for (int i = 0; i < b; ++i)
#define all(x) x.begin(), x.end()

using ld = long double;
using ll = long long;
using vi = vector<int>;
using pll = pair<ll, ll>;

const int V = 10005;
const int INF = 1000000007;
const ld s2 = 1.4142135623730951;
const ld l2 = log(2);
const ld e = 2.718281828459045;
const ld eps = 1e-13;

vi g[V];
vi ans[V];
ll id = 1;
bool vis[V];
priority_queue<pll> pq;
void dfs(int x, int px){
    // cout << x << endl;
    if(ans[x].size() == 2){
        return;
    }
    ans[x].push_back(id++);
    for(auto e : g[x]){
        if(e != px){
            ans[e].push_back(ans[x][1]);
            dfs(e, x);
        }
    }
    return;
}

signed main () {
    IOS;
    int n;
    cin >> n;
    int a, b;
    for (int i = 1; i < n; ++i){
        cin >> a >> b, --a, --b, g[a].pb(b), g[b].pb(a);
    }
    if(n == 2){
        cout << "1 2\n2 1\n";
        return 0;
    }
    for(int i = 0; i < n; i++){
        if(g[i].size() == 1){
            ans[i].push_back(0);
            dfs(i, i);
            break;
        }
    }
    for(int i = 0; i < n; i++){
        if(ans[i].size() < 2){
            ans[i].push_back(0);
        }
    }
    for(int i = 0; i < n; i++){
        cout << ans[i][0] << ' ' << ans[i][1] << endl;
    }

}
/*
14
1 2
1 3
1 4
2 5
2 6
3 7
4 8
4 9
4 10
7 11
7 12
7 13
7 14

*/