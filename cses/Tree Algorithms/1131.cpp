#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 200005;

int n, a, b;
vector<int> e[MAX_N];
int deepest = 0, id = 1;
void DFS(int depth, int cur, int parent){
    if(depth > deepest){
        deepest = depth;
        id = cur;
    }
    for(auto i : e[cur]){
        if(i != parent){
            DFS(depth + 1, i, cur);
        }
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    rep(i, 1, n){
        cin >> a >> b;
        e[a].emplace_back(b);
        e[b].emplace_back(a);
    }
    DFS(0, 1, 1);
    DFS(0, id, id);
    cout << deepest << '\n';
    return 0;
}