#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N,M,x,y; 
    queue<int> togox,togoy;//待前往的x,y佇列 
    
    cin>>N>>M;//迷宮大小 
    
    bool migon[N][M];//紀錄迷宮是否可走 
    int ans[N][M];//紀錄到達迷宮的某個位置時，他離原點的最近距離 
    memset(ans,0,sizeof(ans)); 
    
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>migon[i][j];

    cin>>x>>y;
    togox.push(x);//把起點丟進要前往的佇列 
    togoy.push(y);
    cin>>x>>y;//紀錄終點位置 
    while(!togox.empty())//直到沒有地方能去為止 
    {
        //現在的點 x,y座標 
        int wx=togox.front(),wy=togoy.front();
        togox.pop();
        togoy.pop();
        if(wx==x&&wy==y)//如果到達終點，輸出終點的最佳路徑 
        {
            cout<<ans[wx][wy]<<"\n";
            return 0;//結束程式 
        }
        
        //如果往下的點沒超出迷宮範圍，並且可以走 
        if(wx+1<N&&migon[wx+1][wy]==0)//下 
        {
            togox.push(wx+1);//把這個位置丟進去要去的佇列 
            togoy.push(wy);
            migon[wx+1][wy]=1;//把這個點標記為1(也就是不會再進來了) 
            ans[wx+1][wy]=ans[wx][wy]+1;//此點最佳路徑為上點最佳路徑+1 
        } 
        if(wx-1>-1&&migon[wx-1][wy]==0)//上 
        {
            togox.push(wx-1);
            togoy.push(wy);
            migon[wx-1][wy]=1;
            ans[wx-1][wy]=ans[wx][wy]+1;
        } 
        if(wy-1>-1&&migon[wx][wy-1]==0)//左 
        {
            togox.push(wx);
            togoy.push(wy-1);
            migon[wx][wy-1]=1;
            ans[wx][wy-1]=ans[wx][wy]+1;
        } 
        if(wy+1<M&&migon[wx][wy+1]==0)//右 
        {
            togox.push(wx);
            togoy.push(wy+1);
            migon[wx][wy+1]=1;
            ans[wx][wy+1]=ans[wx][wy]+1;
        }
    }
    cout<<"-1\n";//無法到達終點 
    return 0;
}
