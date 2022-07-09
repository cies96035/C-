#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 1e5 + 5;
int n, m, a, b;
vector<int> edge[MAX_N];
int par[MAX_N];
vector<int> ans;

void DFS(int cur, int p){
    if(par[cur] != -1){
        int tmp = cur;
        do{
            ans.push_back(tmp);
            tmp = par[tmp];
        }while(tmp != cur);
    }
    for(auto e : edge[cur]){
        if(e != p){
            DFS(e, cur);
        }
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    memset(par, -1, sizeof(par));
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    
    return 0;
}