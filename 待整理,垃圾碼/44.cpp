#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N,M,x,y;
    stack<int> togox,togoy;
    cin>>N>>M;
    bool migon[N][M];
    int ans[N][M];
    memset(ans,0,sizeof(ans));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>migon[i][j];
        }
    }
    cin>>x>>y;
    togox.push(x);
    togoy.push(y);
    cin>>x>>y;
    while(!togox.empty())
    {
        //�{�b���I x,y�y�� 
        int wx=togox.top(),wy=togoy.top();
        if(wx==x&&wy==y)
        {
            cout<<ans[wx][wy]<<"\n";
            return 0;
        }
        togox.pop();
        togoy.pop();
        if(wx+1<N&&migon[wx+1][wy]==0)//�U 
        {
            togox.push(wx+1);
            togoy.push(wy);
            migon[wx+1][wy]=1;
            ans[wx+1][wy]=ans[wx][wy]+1;
        } 
        if(wy+1<M&&migon[wx][wy+1]==0)//�k 
        {
            togox.push(wx);
            togoy.push(wy+1);
            migon[wx][wy+1]=1;
            ans[wx][wy+1]=ans[wx][wy]+1;
        } 
        if(wx>0&&migon[wx-1][wy]==0)//�W 
        {
            togox.push(wx-1);
            togoy.push(wy);
            migon[wx-1][wy]=1;
            ans[wx-1][wy]=ans[wx][wy]+1;
        }
        if(wy>0&&migon[wx][wy-1]==0)//�� 
        {
            togox.push(wx);
            togoy.push(wy-1);
            migon[wx][wy-1]=1;
            ans[wx][wy-1]=ans[wx][wy]+1;
        } 
    }
    cout<<"-1\n";
    return 0;
}
