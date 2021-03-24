#include<iostream>
#include<algorithm>
using namespace std;
using pii = pair<int, int>;

const int MAX_N = 2600;
struct EDGE{
    int u, v;
    int c;
    bool operator < (const EDGE &x)const{
        return c < x.c;
    }
}edge[MAX_N * MAX_N];

int n;
int dSet[MAX_N];
int eId;
int cost;

void Init(int x){
    for(int i = 0; i < x; i++){
        dSet[i] = i;
    }
}
int Find(int x){
    return dSet[x] == x ? x : dSet[x] = Find(dSet[x]);
}
void Union(int a, int b){
    dSet[Find(a)] = dSet[Find(b)];
}
bool Same(int a, int b){
    return Find(a) == Find(b);
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    Init(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> cost;
            if(i < j){
                edge[eId].u = i;
                edge[eId].v = j;
                edge[eId].c = cost;
                eId++;
            }
        }
    }
    
    sort(edge, edge + eId);
    for(int i = 0 ; i < eId; i++){
        if(Same(edge[i].u, edge[i].v)){
            continue;
        }
        Union(edge[i].u, edge[i].v);
        cout << edge[i].u + 1 << ' ' << edge[i].v + 1 << '\n';
    }
    return 0;
}