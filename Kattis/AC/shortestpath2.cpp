#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

const int MAX_N = 10100;
struct Edge{
    int v;
    int t0;
    int p;
    int d;
    Edge(int w, int x, int y, int z){
        v = w;
        t0 = x;
        p = y;
        d = z;
    }
};
struct Node{
    int id;
    int w;
    Node(int a, int b){
        id = a;
        w = b;
    }
    Node(){}
    bool operator<(const Node x)const{
        return w == x.w ? id > x.id : w > x.w;
    }
};
int n, m, q, s;
int u, v, t0, p, d;
bool vis[MAX_N];
int dis[MAX_N];
vector<Edge> edge[MAX_N];
Node tmp;
int newW;
bool blank;

void Init(int x){
    for(int i = 0; i < n; i++){
        dis[i] = INT_MAX;
        vis[i] = false;
        edge[i].clear();
    }

}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> n >> m >> q >> s && n){
        priority_queue<Node> node;
        Init(n);

        for(int i = 0; i < m; i++){
            cin >> u >> v >> t0 >> p >> d;
            edge[u].emplace_back(Edge(v, t0, p, d));
        }
        node.push(Node(s, 0));
        dis[s] = 0;
        while(!node.empty()){
            tmp = node.top();
            node.pop();
            if(vis[tmp.id]){
                continue;
            }
            vis[tmp.id] = true;
            for(auto i : edge[tmp.id]){
                if(dis[tmp.id] <= i.t0){
                    newW = i.t0 + i.d;
                }else if(i.p == 0){
                    continue;
                }else{
                    newW = ((dis[tmp.id] - i.t0 - 1) / i.p + 1) * i.p + i.t0 + i.d;
                }

                if(newW < dis[i.v]){
                    dis[i.v] = newW;
                    node.push(Node(i.v, newW));
                }
            }
        }

        if(blank){
            cout << '\n';
        }else{
            blank = true;
        }
        for(int i = 0; i < q; i++){
            cin >> u;
            if(dis[u] == INT_MAX){
                cout << "Impossible\n";
            }else{
                cout << dis[u] << '\n';
            }
        }
    }
    return 0;
}