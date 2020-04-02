#include<iostream>
#include<queue>
using namespace std;

//22種可能都丟丟看，找最大值 

typedef pair<int,int> pii;

#define in_range nxg[0]>=0&&nxg[0]<Lh&&nxg[1]>=0&&nxg[1]<Lw //界限判定 

const int Lh=14,Lw=6,m[4][2]={{0,1},{1,0},{-1,0},{0,-1}};

char a,b,SC;//a色，b色，SameColor 
string R_puyo[Lh],C_puyo[Lh];//Real/Copy
int vis[Lh][Lw],visid=0,Cvisid=0,maxCmb=0,ComboCnt;
bool haveclear;

bool FindFour(int x,int y)//找特定點是否有四相連 
{
    queue<pii> tg;
    tg.push(pii(x,y));//起點 
    SC=C_puyo[x][y];
    vis[x][y]=visid;
    
    int cnt=4;
    
    while(!tg.empty())
    {
        cnt--;
        if(!cnt)return true;//符合消除條件，回傳 
        for(int i=0;i<4;i++)
        {
            int nxg[2]={tg.front().first+m[i][0],tg.front().second+m[i][1]};
            if(in_range)
            {
                if(C_puyo[nxg[0]][nxg[1]]==SC&&vis[nxg[0]][nxg[1]]<visid)//如果與原點同色，而且此層沒進過層 
                {
                    tg.push(pii(nxg[0],nxg[1]));
                    vis[nxg[0]][nxg[1]]=visid;//標記進過此層 
                }
            }
        }
        tg.pop();
    }
    return false;
}

void clear_puyo(int x,int y)//消除與特定點同色的版面 
{
    queue<pii> tg;
    tg.push(pii(x,y));//起點 
    vis[x][y]=Cvisid;//走過的標記
    
    while(!tg.empty())
    {
        C_puyo[tg.front().first][tg.front().second]='0';//消除
        for(int i=0;i<4;i++)
        {
            int nxg[2]={tg.front().first+m[i][0],tg.front().second+m[i][1]};
            if(in_range)
            {
                if(C_puyo[nxg[0]][nxg[1]]==SC&&vis[nxg[0]][nxg[1]]!=Cvisid)//如果同色，丟入待消除名單 
                {
                    tg.push(pii(nxg[0],nxg[1]));
                    vis[nxg[0]][nxg[1]]=Cvisid;//避免走回頭路 
                }
            }
        }
        tg.pop();
    }
}

void Cmb(int ay,int ax,int by,int bx)//將兩個Puyo放到複製後的版面，並且運行看結果有幾combo 
{
    for(int i=0;i<Lh;i++)//將R複製到C，並且加入到指定位置 
        C_puyo[i]=R_puyo[i];
    C_puyo[ay][ax]=a;
    C_puyo[by][bx]=b;
    
    ComboCnt=0;//計算此嘗試的Combo數 
    haveclear=true;//判斷還有沒有可以消除的
    while(haveclear)
    { 
        visid++;
        Cvisid--;
        haveclear=false;//先假設此層沒有消除過 
        
        //1.先把所有浮在空中的，移至最底
        for(int i=0;i<Lw;i++)
            for(int j=Lh-1,k=j-1;k>=0;j--,k--)
                if(C_puyo[j][i]=='0')//如果是空的，把最下面此列最下面的puyo抓下來 
                {
                    while(C_puyo[k][i]=='0'&&k>0)k--;
                    swap(C_puyo[k][i],C_puyo[j][i]);
                }
                
        
        //2.搜尋是否有四連珠，有->flg=1(繼續迴圈),並且bfs第二次->消除，全部變0 
        for(int i=Lh-1;i>0;i--)
            for(int j=0;j<Lw;j++)
                if(C_puyo[i][j]!='0'&&vis[i][j]<visid)//如果這格有puyo，而且在這層沒有被BFS過 
                {
                    if(FindFour(i,j))
                    {
                        haveclear=true;
                        clear_puyo(i,j);//達到4相連，消除該組puyo 
                    }
                }
        if(haveclear)                
            ComboCnt++;//如果此層有消除 
    } 
    maxCmb=max(maxCmb,ComboCnt);//更新最大combo數 
    return;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin>>a>>b;
    R_puyo[0]=R_puyo[1]="000000";//預留兩行 
    for(int i=2;i<Lh;i++)
        cin>>R_puyo[i];
    
    //每個位置的puyo都測試看看
    for(int i=0;i<5;i++) 
    {
        Cmb(0,i,0,i+1);
        Cmb(0,i+1,0,i);
        Cmb(1,i,0,i);
        Cmb(0,i,1,i);
    }
    Cmb(0,5,1,5);
    Cmb(1,5,0,5);
    
    cout<<maxCmb<<'\n';
    return 0;
}
