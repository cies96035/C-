#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)


const int MAX_N = 2e5 + 5;
const ll M = 1e9 + 7;
const ll M2 = 998244353;
ll hashFunc(ll v, ll u){
    return (v * M) % M2 * M2 + u * M;
}
struct NODE{
    vector<int> ch;
    int val;
}nodes[MAX_N];

void DFS2(int cur, int par){
    vector<pll> vals;
    for(auto nx:nodes[cur].ch){
        if(nx != par){
            vals.push_back({nodes[nx].val, nx});
        }
    }
    map<ll, ll> cnt;
    int d = 0;
    map<ll, ll> tmp;
    for(auto v:vals){
        cnt[v.first]++;
        if(cnt[v.first] % 2) {
            d++;
            tmp[v.first] = v.second;
        }
        else{
            tmp.erase(v.first);
            d--;
        }
    }
    if(d == 0){
        cout << "YES\n";
    }
    else if(d > 1) {
        cout << "NO\n";
    }
    else{
        DFS2(tmp.begin()->second, cur);
    }
}
void DFS(int cur, int par){
    vector<ll> vals;
    for(auto nx:nodes[cur].ch){
        if(nx != par){
            DFS(nx, cur);
            vals.push_back(nodes[nx].val);
        }
    }
    sort(vals.begin(), vals.end());

    nodes[cur].val = 1;
    for(auto v: vals){
        nodes[cur].val = hashFunc(nodes[cur].val, v);
    }

}
void f(){
    int n;
    cin >> n;
    int u, v;
    rep(i, 1, n){
        cin >> u >> v;
        nodes[u].ch.push_back(v);
        nodes[v].ch.push_back(u);
    }
    DFS(1, 0);
    DFS2(1, 0);
    rrep(i, 1, n) nodes[i].ch.clear();
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