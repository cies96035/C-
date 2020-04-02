#include<iostream>
using namespace std;

#define LUC(i) (i*4-2)//左上 
#define RUC(i) (i*4-1)//右上 
#define LDC(i) (i*4)  //左下 
#define RDC(i) (i*4+1)//右下 
#define midx (lx+rx)/2//水平的中間值 
#define midy (uy+dy)/2//垂直的中間值 

int n,m,q,num[3100][3100];
int x1,x2,y1,y2;
long long Ans;
int xx,yy,k;

//儲存和，空間:(log2邊長)^4 
unsigned int sum[223696213];

//建表:(現在座標,左邊界,右邊界,上邊界,下邊界) 
void build(int ID,int lx,int rx,int uy,int dy)
{
	//如果上下邊界，左右邊界相等，剩下一格，紀錄下來，不再遞迴 
    if(lx==rx&&uy==dy)
    {
        sum[ID]=num[lx][uy];
        return; 
    }
    //如果左右邊界相等(垂直長條狀)->遞迴從中間切成兩條 
    else if(lx==rx)
    {
        build(LUC(ID),lx,rx,uy,midy);
        build(LDC(ID),lx,rx,midy+1,dy);
    }
    //如果上下邊界相等(水平長條狀)->遞迴從中間切成兩半 
    else if(uy==dy)
    {
        build(LUC(ID),lx,midx,uy,dy);
        build(RUC(ID),midx+1,rx,uy,dy);
    }
    //如果都不相等，切成四塊往下遞迴 
    else
    {
        build(LUC(ID),lx,midx,uy,midy);
        build(LDC(ID),lx,midx,midy+1,dy);
        build(RUC(ID),midx+1,rx,uy,midy);
        build(RDC(ID),midx+1,rx,midy+1,dy);
    }
    //結束遞迴後，得到四個角落的總和，再相加就為此範圍的總和 
    sum[ID]=sum[LUC(ID)]+sum[LDC(ID)]+sum[RUC(ID)]+sum[RDC(ID)];
}

//現在位置,左邊界,右邊界,上邊界,下邊界 
void query(int ID,int lx,int rx,int uy,int dy)
{
	//此ID與搜索範圍沒有交集，離開搜索 
    if(x2<lx||rx<x1||y2<uy||dy<y1)return;
    if((x1<=lx&&rx<=x2)&&(y1<=uy&&dy<=y2))//此ID完全在搜索範圍內，進行加總 
    {
        Ans+=sum[ID];
        return;
    }
    //如果有交集，切成四塊往下遞迴，直到->完全沒交集or完全包含 
    query(LUC(ID),lx,midx,uy,midy);
    query(RUC(ID),midx+1,rx,uy,midy);
    query(LDC(ID),lx,midx,midy+1,dy);
    query(RDC(ID),midx+1,rx,midy+1,dy);
}

//將所有包含要改變位置的ID做修改，並往下遞迴 
void change(int ID,int lx,int rx,int uy,int dy)
{
	//更新值 
	sum[ID]+=k-num[xx][yy];
	
    if(lx==rx&&uy==dy)//到底部了，結束遞迴 
        return;
        
    else if(xx<=midx&&yy<=midy)
        change(LUC(ID),lx,midx,uy,midy);
    else if(xx>midx&&yy<=midy)
        change(RUC(ID),midx+1,rx,uy,midy);
    else if(xx<=midx&&yy>midy)
        change(LDC(ID),lx,midx,midy+1,dy);
    else if(xx>midx&&yy>midy)
        change(RDC(ID),midx+1,rx,midy+1,dy);
    return;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>num[i][j];
    
    //建表 
    build(1,1,n,1,m);
    
    cin>>q;
    while(q--)
    {
        char ask;
        cin>>ask;
        if(ask=='Q')
        {
            cin>>x1>>y1>>x2>>y2;
            Ans=0;//每次回答都要初始化Ans 
            query(1,1,n,1,m);
            cout<<Ans<<'\n';
        }
        else if(ask=='C')
        {
            cin>>xx>>yy>>k;
            change(1,1,n,1,m);
            num[xx][yy]=k;
        }
    }
    return 0;
}
