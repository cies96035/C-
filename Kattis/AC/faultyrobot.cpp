#include<iostream>
#include<vector>
using namespace std;

const int MAX_N = 1010;
int vis[MAX_N];
bool stop[MAX_N];
int n;
int m;
vector<int> blackEdge[MAX_N];
vector<int> redEdge[MAX_N];
int s, e;
int cnt;
void DFS(int i, bool black){
    if(vis[i] > 2){
        return;
    }else if(vis[i] == 2 && black){
        return;
    }else if(vis[i] == 1 && !black){
        return;
    }else if(vis[i]){
        vis[i] = 3;
    }else{
        vis[i] = 1 + black;
    }
    if(redEdge[i].empty()){
        if(!stop[i]){
            stop[i] = true;
            cnt++;
        }
    }else{
        for(auto x : redEdge[i]){
            DFS(x, black);
        }
    }
    if(!black){
        for(auto x : blackEdge[i]){
            DFS(x, true);
        }
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> s >> e;
        if(s < 0){
            redEdge[-s].emplace_back(e);
        }else{
            blackEdge[s].emplace_back(e);
        }
    }
    DFS(1, false);
    cout << cnt << '\n';
    return 0;
}