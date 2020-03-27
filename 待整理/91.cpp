//不考慮快慢，暴力解 
//寫靠北長 
//寫那麼亂也是奇才吧 
//這題應該是要用爆搜... 
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

#define xlen len[m].first
#define ylen len[m].second
int Map[4][4],ans=0,k;
const pair<int,int> len[4]={{1,1},{2,2},{4,2},{4,4}},
h[9]={{4,4},{2,4},{1,4},{4,2},{4,1},{2,2},{2,1},{1,2},{1,1}};
bool query(int m)
{
    for(int i=0;i<xlen;i++)
        for(int j=0;j<ylen;j++)
            if(Map[i][j]==1)return 0;
    cout<<ans<<'\n';
    return 1;
}
//特判，十字陷阱 
bool check(int x,int y,int xl,int yl,int m,bool isedit)
{
    bool f=1;
    for(int i=0;i<xl;i++)
        for(int j=0;j<yl;j++)
            if(isedit)Map[(i+x)%xlen][(y+j)%ylen]=-1;
            else if(Map[(i+x)%xlen][(y+j)%ylen]==0)return 0;
            else if(Map[(i+x)%xlen][(y+j)%ylen]==1)f=0;
    if(xl==2&&yl==2)
    {
        if(Map[x][y]==-1&&Map[(x+1)%4][y]==-1)
            if(Map[x][(y+yl)%4]==1||Map[(x+1)%4][(y+yl)%4]==1)return 0;
        if(Map[x][y]==-1&&Map[x][(y+1)%4]==-1)
            if(Map[(x+xl)%4][y]==1||Map[(x+xl)%4][(y+1)%4]==1)return 0;
    }
    else if(xl==2)
    {
        if(Map[x][y]==-1)
            if(Map[(x+xl)%4][y]==1)return 0;
    }
    else if(yl==2)
    {
        if(Map[x][y]==-1)
            if(Map[x][(y+yl)%4]==1)return 0;
    }
    if(f&&!isedit)return 0;
    
    if(!isedit)ans++;
    if(!isedit)return check(x,y,xl,yl,m,1);
    else return 0;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int m,input,p[4]={0,1,3,2},kk[4]={8,5,3,0};
    cin>>m;
    m--;
    while(cin>>input)
    {
        if(input==-1)break;
        if(m<2)
            Map[input%2][input/2]=1;
        else
            Map[p[input%4]][p[input/4]]=1;
    }
    if(query(m))return 0;
    for(k=kk[m];k<9;k++)
        for(int i=0;i<xlen;i++)
            for(int j=0;j<ylen;j++)
                if(check(i,j,h[k].first,h[k].second,m,0))return 0;
}
