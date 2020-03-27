#include<iostream>
using namespace std;

#define LUC(i) (i*4-2)
#define RUC(i) (i*4-1)
#define LDC(i) (i*4) 
#define RDC(i) (i*4+1)
#define midx (lx+rx)/2
#define midy (uy+dy)/2
short num[3100][3100];

struct Node
{
    unsigned int sum;
}node[223696213];
//空間:(log2邊長)^4 

void build(int root,int lx,int rx,int uy,int dy)
{
    if(lx==rx&&uy==dy)//切到剩一個為止 
    {
        node[root].sum=num[lx][uy];
        return; 
    }
    if(lx==rx)
    {
        build(LUC(root),lx,rx,uy,midy);
        build(LDC(root),lx,rx,midy+1,dy);
    }
    else if(uy==dy)
    {
        build(LUC(root),lx,midx,uy,dy);
        build(RUC(root),midx+1,rx,uy,dy);
    }
    else
    {
        build(LUC(root),lx,midx,uy,midy);
        build(LDC(root),lx,midx,midy+1,dy);
        build(RUC(root),midx+1,rx,uy,midy);
        build(RDC(root),midx+1,rx,midy+1,dy);
    }
    node[root].sum=node[LUC(root)].sum+node[LDC(root)].sum+node[RUC(root)].sum+node[RDC(root)].sum;
}
long long sum,x1,x2,y1,y2;
void query(int root,int lx,int rx,int uy,int dy)
{
    if(x2<lx||rx<x1||y2<uy||dy<y1)return;//範圍外，離開搜索 
    if((x1<=lx&&rx<=x2)&&(y1<=uy&&dy<=y2))//範圍內，納入計算 
    {
        sum+=node[root].sum;
        return;
    }
    query(LUC(root),lx,midx,uy,midy);
    query(RUC(root),midx+1,rx,uy,midy);
    query(LDC(root),lx,midx,midy+1,dy);
    query(RDC(root),midx+1,rx,midy+1,dy);
}

int ii,jj,k;
void change(int root,int lx,int rx,int uy,int dy)
{
    if(lx==rx&&uy==dy)
    {
        node[root].sum=k;
        return;
    }
    if(ii<=midx&&jj<=midy)
        change(LUC(root),lx,midx,uy,midy);
    if(ii>midx&&jj<=midy)
        change(RUC(root),midx+1,rx,uy,midy);
    if(ii<=midx&&jj>midy)
        change(LDC(root),lx,midx,midy+1,dy);
    if(ii>midx&&jj>midy)
        change(RDC(root),midx+1,rx,midy+1,dy);
    node[root].sum=node[LUC(root)].sum+node[LDC(root)].sum+node[RUC(root)].sum+node[RDC(root)].sum;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n,m,q;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>num[i][j];
    build(1,0,n-1,0,m-1);
    cin>>q;
    while(q--)
    {
        char ask;
        cin>>ask;
        if(ask=='Q')
        {
            cin>>x1>>y1>>x2>>y2;
            x1--,x2--,y1--,y2--,sum=0;
            query(1,0,n-1,0,m-1);
            cout<<sum<<'\n';
        }
        else if(ask=='C')
        {
            cin>>ii>>jj>>k;
            ii--,jj--;
            change(1,0,n-1,0,m-1);
        }
    }
    return 0;
}
