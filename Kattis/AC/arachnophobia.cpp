#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAX_N = 100100;
const int BIGINT = 2000002000;
int N, M, T;
int u, v, d;
int s, t;
int K, a;

int spiderD[MAX_N];
vector<pii> Edge[MAX_N];

int vis[MAX_N], visId;
pii tmp;

int Lower = 0, Upper = 0, Middle;

//test if can find a path <= T and don't closer any spider than D
bool test(int D){
    if(spiderD[s] < D){
        return false;
    }

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push( pii(0, s) );

    while(!pq.empty()){
        tmp = pq.top();
        pq.pop();
        if(vis[tmp.second] == visId){
            continue;
        }else if(tmp.second == t){
            return tmp.first <= T;
        }

        vis[tmp.second] = visId;

        for(pii i : Edge[tmp.second]){
            if(spiderD[i.second] >= D){
                pq.push( pii(tmp.first + i.first, i.second) );
            }
        }
    }
    return false;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    priority_queue<pii, vector<pii>, greater<pii> > pq;

    cin >> N >> M >> T;
    for(int i = 0; i < M; i++){
        cin >> u >> v >> d;
        Edge[u].push_back( pii(d, v) );
        Edge[v].push_back( pii(d, u) );
    }

    cin >> s >> t;

    cin >> K;
    for(int i = 0; i < K; i++){
        cin >> a;
        pq.push(pii(0, a));
    }

    //for every node find the closet spider distance
    for(int i = 0; i < N; i++){
        spiderD[i] = BIGINT;
    }
    while(!pq.empty()){
        tmp = pq.top();
        pq.pop();
        if(spiderD[tmp.second] > tmp.first){
            if(Upper < tmp.first){
                Upper = tmp.first;
            }
            spiderD[tmp.second] = tmp.first;
            for(auto i : Edge[tmp.second]){
                if(spiderD[i.second] == BIGINT){
                    pq.push( pii(tmp.first + i.first, i.second) );
                }
            }
        }
    }

    Upper++;
    while(Lower < Upper){
        visId++;
        Middle = (Lower + Upper) / 2;
        if(test(Middle)){
            Lower = Middle + 1;
        }else{
            Upper = Middle;
        }
    }
    cout << Lower - 1 << '\n';
    return 0;
}