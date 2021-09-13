#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i <= b; i++)

const int MAX_N = 1e5 + 5;
int n, m;
int a, b;
struct Node{
    vector<int> nx;
    int color;
}node[MAX_N];

bool flg = true;
void DFS(int cur, bool color){
    if(node[cur].color){
        if(color + 1 != node[cur].color){
            flg = false;
        }
    }else{
        node[cur].color = color + 1;
        for(auto nx : node[cur].nx){
            DFS(nx, !color);
        }
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    rep(i, 1, m){
        cin >> a >> b;
        node[a].nx.push_back(b);
        node[b].nx.push_back(a);
    }
    rep(i, 1, n){
        if(!node[i].color){
            DFS(i, 0);
        }
    }
    if(flg){
        rep(i, 1, n){
            cout << node[i].color << ' ';
        }
        cout << '\n';
    }else{
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}