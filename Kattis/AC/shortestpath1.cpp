#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MAX_N = 10100;
const int MAX_INT = 300030000;
int n, m, q, s;
int u, v, w;
struct EDGE{
    int v, w;
    EDGE(int a, int b):v(a), w(b){};
};
struct POINT{
    int id;
    int cost;
    bool operator <(const POINT & x) const{
        return cost > x.cost;
    }
    POINT(int a, int b):id(a), cost(b){};
    POINT(){};
};

priority_queue<POINT> pq;
vector<EDGE> e[MAX_N];
POINT tmp;
int Min_Dis[MAX_N];
int used[MAX_N], usedId;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> n >> m >> q >> s && (n || m || q || s)){
        usedId++;
        pq.push(POINT(s, 0));
        for(int i = 0; i < n; i++){
            e[i].clear();
        }
        for(int i = 0; i < m; i++){
            cin >> u >> v >> w;
            e[u].emplace_back(EDGE(v, w));
        }
        while(!pq.empty()){
            tmp = pq.top();
            pq.pop();
            if(used[tmp.id] != usedId){
                Min_Dis[tmp.id] = tmp.cost;
                used[tmp.id] = usedId;
                for(auto i : e[tmp.id]){
                    pq.push(POINT(i.v, i.w + tmp.cost));
                }
            }
        }
        while(q--){
            cin >> w;
            if(used[w] != usedId){
                cout << "Impossible\n";
            }else{
                cout << Min_Dis[w] << '\n';
            }
        }
        cout << '\n';
    }
    return 0;
}