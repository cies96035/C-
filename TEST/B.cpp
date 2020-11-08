#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N,M;

struct Edge
{
    int id;
    int val;
    Edge()
    {
        id=-1;
        val=-1;
    }
    Edge(int a,int b)
    {
        id=a;
        val=b;
    }
};
vector<Edge> E[50];
int minw=2e9;
void bfs(bool vis[50],int w,int p,int n)
{
    if(n==0)
    {
        for(int i=0;i<E[p].size();i++)
        {
            if(E[p][i].id==0)
            {
                minw=min(minw,w+E[p][i].val);
            }
        }
        return;
    }

    bool v[50];
    for(int i=0;i<50;i++)
        v[i]=vis[i];
    v[p]=1;
        
    for(int i=0;i<E[p].size();i++)
    {
        if(vis[E[p][i].id]==0)
        {
            bfs(v,w+E[p][i].val,E[p][i].id,n-1);
        }
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--)
    {
        for(int i=0;i<50;i++)
            E[i].clear();
        minw=2e9;

        cin>>N>>M;

        for(int i=0;i<M;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            E[a].push_back(Edge(b,c));
        }
        bool vis[50]={0};
        bfs(vis,0,0,N-1);
        cout<<minw<<endl;
    }
    return 0;
}