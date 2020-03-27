#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

typedef pair<int,int> pii;

int main() {
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N,M,start,end;
    cin>>N>>M;
    
    queue<pii> link[N];
    int ans[N];
    bool visited[N]={0};
    memset(ans,-1,sizeof(ans));
    for(int i=0;i<M;i++)
    {
        int A,B,L;
        cin>>A>>B>>L;
        link[B].push(pii(A,L));
        link[A].push(pii(B,L));
    }
    
    cin>>start>>end;
    queue<int> togo;
    togo.push(start);
    ans[start]=0;
    visited[start]=1;
    
    while(!togo.empty())
    {
        int now=togo.front(),min=2e9,minid;
        if(now==end)break;
        togo.pop();
        while(!link[now].empty())
        {
            int i=link[now].front().first,value=ans[now]+link[now].front().second;
            link[now].pop();
            if(visited[i])continue;
            if(ans[i]>value||ans[i]==-1)ans[i]=value;
        }
        for(int i=0;i<N;i++)
        {
            if(visited[i])continue;
            if(ans[i]<min&&ans[i]>=0)
            {
                min=ans[i];
                minid=i;
            }
        }
        visited[minid]=1;
        togo.push(minid);
    }
    
    cout<<ans[end]<<'\n';
    
    return 0;
}
