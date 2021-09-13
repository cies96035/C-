#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)

const int MAX_N = 1e5 + 5;
const int MAX_M = 2e5 + 5;

int n, m, u, v;
int par[MAX_N];
vector<int> edge[MAX_M];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    memset(par, -1, sizeof(int) * (n + 1));
    rep(i, 0, m){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    par[1] = 0;
    while(!q.empty()){
        if(q.front() == n){
            break;
        }
        for(auto nx : edge[q.front()]){
            if(par[nx] == -1){
                par[nx] = q.front();
                q.push(nx);
            }
        }
        q.pop();
    }
    if(par[n] != -1){
        stack<int> ans;
        while(n){
            ans.push(n);
            n = par[n];
        }
        cout << ans.size() << '\n';
        while(!ans.empty()){
            cout << ans.top() << ' ';
            ans.pop();
        }
        cout << '\n';
    }else{
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}