#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 1e5 + 5;
int n, m, u, v, w;
ll ans[MAX_N];
vector<pll> edge[MAX_N];
priority_queue<pll, vector<pll>, greater<pll>> pq;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    rep(i, 0, m){
        cin >> u >> v >> w;
        edge[u].push_back({w, v});
    }
    memset(ans, -1, sizeof(ans));
    pq.push({0, 1});

    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(ans[cur.second] == -1){
            ans[cur.second] = cur.first;
            for(auto e : edge[cur.second]){
                pq.push({e.first + cur.first, e.second});
            }
        }
    }
    rrep(i, 1, n){
        cout << ans[i] << ' ';
    }cout << '\n';
    return 0;
}