#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
using ld = long double;

const int MAX_N = 2020;

struct EDGE{
    int u;
    int v;
    ld w;
    bool operator<(const EDGE &x){
        return w < x.w;
    }
}edge[MAX_N * MAX_N];
int edgeid;

struct V{
    int x;
    int y;
    int r;
}v[MAX_N];

int SET[MAX_N];
int N;
int dx, dy;
ld W;

void Init(int x){
    for(int i = 0; i < x; i++){
        SET[i] = i;
    }
}

int Find(int x){
    return SET[x] == x ? x : SET[x] = Find(SET[x]);
}

void Union(int a, int b){
    SET[Find(a)] = Find(b);
}

bool Same(int a, int b){
    return Find(a) == Find(b);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> v[i].x >> v[i].y >> v[i].r;
    }

    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            edge[edgeid].u = i;
            edge[edgeid].v = j;
            dx = v[i].x - v[j].x;
            dy = v[i].y - v[j].y;
            edge[edgeid].w = sqrt(dx * dx + dy * dy) - v[i].r - v[j].r;
            edgeid++;
        }
    }

    sort(edge, edge + edgeid);
    Init(N);
    for(int i = 0; i < edgeid; i++){
        if(Same(edge[i].u, edge[i].v)){
            continue;
        }
        Union(edge[i].u, edge[i].v);
        W += edge[i].w;
    }
    cout << fixed << setprecision(8) << W << '\n';
    return 0;
}