#include<iostream>
#include<vector>
using namespace std;

const int MAX_MN = 500500;
int M, N;
int odd, even;

vector<int> edge[MAX_MN];
bool vis[MAX_MN];
bool visSET[MAX_MN];
int SET[MAX_MN];
int u, v;

void Init(int x){
    for(int i = 1; i <= x; i++){
        SET[i] = i;
    }
}

int Find(int x){
    return SET[x] == x ? x : SET[x] = Find(SET[x]);
}

void Union(int a, int b){
    SET[Find(a)] = Find(b);
}

void travel(int x, bool hop){
    if(vis[x] && hop){
        return;
    }
    if(hop){
        vis[x] = true;
    }
    for(auto u : edge[x]){
        travel(u, !hop);
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M;
    Init(N);

    for(int i = 0; i < M; i++){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
        Union(u, v);
    }

    for(int i = 1; i <= N; i++){
        if(vis[i]){
            continue;
        }else if(visSET[Find(i)]){
            odd--;
            even++;
        }else if(edge[i].empty()){
            even++;
            continue;
        }else{
            odd++;
            visSET[Find(i)] = true;
        }
        travel(i, true);
    }
    
    if(odd){
        cout << even + odd - 1 << '\n';
    }else{
        cout << even << '\n';
    }
    return 0;
}