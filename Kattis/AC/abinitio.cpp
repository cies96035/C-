#include<iostream>
using namespace std;
using ll = long long;

const int MAX_V = 4020;
const ll M = 1000000007;
const ll Limit = 1e16;
bool Edge[MAX_V][MAX_V];
bool transpose = 0;
bool EdgeExist = 1;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int V, E, Q;
    int a, b, q;
    int cnt = 0;
    ll hash = 0;
    cin >> V >> E >> Q;
    for(int i = 0; i < E; i++)
    {
        cin >> a >> b;
        Edge[a][b] = EdgeExist;
    }
    while(Q--)
    {
        cin >> q;
        if(q == 1){
            for(int i = 0; i < V; i++)
                if(!EdgeExist)
                    Edge[i][V] = Edge[V][i] = !EdgeExist;
            V++;
        }else if(q == 2){
            cin >> a >> b;
            if(transpose){
                swap(a, b);
            }
            Edge[a][b] = EdgeExist;
        }else if(q == 3){
            cin >> a;
            for(int i = 0; i < V; i++)
                Edge[a][i] = Edge[i][a] = !EdgeExist;
        }else if(q == 4){
            cin >> a >> b;
            if(transpose){
                swap(a, b);
            }
            Edge[a][b] = !EdgeExist;
        }else if(q == 5){
            transpose = !transpose;
        }else{
            EdgeExist = !EdgeExist;
        }
    }

    cout << V << '\n';

    if(transpose){
        for(int i = 0; i < V; i++)
        {
            cnt = 0;
            hash = 0;
            for(int j = V - 1; j >= 0; j--)
            {
                if(i == j)
                    continue;
                if(Edge[j][i] == EdgeExist){
                    cnt++;
                    hash = hash * 7 + j;
                }
                if(hash >= Limit)
                    hash %= M;
            }
            cout << cnt << ' ' << hash % M << '\n';
        }
    }else{
        for(int i = 0; i < V; i++)
        {
            cnt = 0;
            hash = 0;
            for(int j = V - 1; j >= 0; j--)
            {
                if(i == j)
                    continue;
                if(Edge[i][j] == EdgeExist){
                    cnt++;
                    hash = hash * 7 + j;
                }
                if(hash >= Limit)
                    hash %= M;
            }
            cout << cnt << ' ' << hash % M << '\n';
        }
    }
    return 0;
}