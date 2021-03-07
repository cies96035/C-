#include<iostream>
#include<vector>
using namespace std;

const int MAX_NM = 1000100;
vector<int> edge[MAX_NM];
int vis[MAX_NM];
bool possible;
int u, v;
int Tsort[MAX_NM];
int pos[MAX_NM];
int Tid;
int N, M;

void DFS(int x){
    if(vis[x]){
        return;
    }
    vis[x] = true;
    for(auto v : edge[x]){
        DFS(v);
    }
    pos[x] = Tid;
    Tsort[Tid--] = x;
}

bool CycleCheck(){

    for(int i = 1; i <= N; i++){
        for(auto v : edge[i]){
            if(pos[v] < pos[i]){
                return false;
            }
        }
    }
    return true;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    Tid = N - 1;

    for(int i = 0; i < M; i++){
        cin >> u >> v;
        edge[u].push_back(v);
    }

    possible = true;
    for(int i = 1; i <= N; i++){
        DFS(i);
    }

    if(CycleCheck()){
        for(int i = 0; i < N; i++){
            cout << Tsort[i] << '\n';
        }
    }else{
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}
/*
9 12
1 3
1 5
1 6
2 4
2 6
2 7
4 3
6 3
6 4
6 5
7 4
8 6
*/