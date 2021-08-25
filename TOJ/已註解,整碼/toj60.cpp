#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 5e3 + 5;
const int MAX_M = 1e5 + 5;

int n, m, k;
ll ans = 0;
struct Edge{
    int i, j;
    ll w;
    bool operator <(const Edge &x){
        return w < x.w;
    }
}e[MAX_M];

int DSU[MAX_N];
inline void Init(int x){
    for(int i = 1; i <= x; i++){
        DSU[i] = i;
    }
}
int Find(int x){
    return x == DSU[x] ? x : DSU[x] = Find(DSU[x]);
}
void Union(int a, int b){
    DSU[Find(a)] = Find(b);
}
inline bool Same(int a, int b){
    return Find(a) == Find(b);
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m >> k;

    Init(n);
    if(k == -1) k = n;
    else if(k == 0) k = 1;
    
    rep(i, 0, m){
        cin >> e[i].i >> e[i].j >> e[i].w;
    }
    sort(e, e + m);

    rep(i, 0, m){
        if(e[i].w > 0 && k >= n){ // use k to connect all part
            break;
        }
        if(e[i].w <= 0){ //if w < 0, must take
            if( !Same(e[i].i, e[i].j) ){ //if connect two part
                n--;
            }
            Union(e[i].i, e[i].j);
            ans += e[i].w;
        }else if( !Same(e[i].i, e[i].j) ){
            Union(e[i].i, e[i].j);
            ans += e[i].w;
            n--;
        }
    }
    if(k >= n){
        cout << ans << '\n';
    }else{
        cout << "-1\n";
    }
    return 0;
}