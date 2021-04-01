#include<bits/stdc++.h>
using namespace std;

const int MAX_M = 1100;
int used[MAX_M], usedId;
int cnt;
int n, m, r, a, b;
vector<int> Edge[MAX_M];

void DFS(int pos){
    if(used[pos] == usedId){
        return;
    }
    used[pos] = usedId;
    for(auto e : Edge[pos]){
        DFS(e);
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cnt = -1;
        usedId++;
        cin >> m >> r;
        for(int i = 0; i < r; i++){
            cin >> a >> b;
            Edge[a].emplace_back(b);
            Edge[b].emplace_back(a);
        }
        for(int i = 0; i < m; i++){
            if(used[i] != usedId){
                cnt++;
                DFS(i);
            }
            Edge[i].clear();
        }
        cout << cnt << '\n';
    }
    return 0;
}