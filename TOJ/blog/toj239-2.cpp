#include<iostream>
using namespace std;

const int maxNode = 4000000;

//左子節點和右子節點的座標位置 
#define LC (now*2)
#define RC (now*2+1) 
#define M (L+R)/2

struct Node
{
    int max,min,flag;
}node[maxNode];

//建造一個H[]的線段數
//now為線段數的座標
//L,R為此點中包含H的位置 
//H*為H[] 
void build(int now,int L,int R,int *H)
{
	node[now].flag=0;
    if(L==R)//到線段樹最底層時，該層數值為H[L]的數值 
    {
        node[now].max=node[now].min=H[L];
        return;
    }
    //若並非最底層，建構底下的左右兩層線段樹
	//一個節點分成兩半
	//分別為L到M(左節點)，M+1到R(右節點) 
    build(LC,L,M,H);
    build(RC,M+1,R,H);
    
    //紀錄此節點左右兩子節點的最大和最小值 
    node[now].max=max(node[LC].max,node[RC].max);
    node[now].min=min(node[LC].min,node[RC].min);
}

//待理解 
void pushdown(int now)
{
	if(node[now].flag)
	{
		long long k=node[now].flag;
		node[LC].flag+=k;
		node[RC].flag+=k;
		node[LC].max+=k;
		node[LC].min+=k;
		node[RC].max+=k;
		node[RC].min+=k;
		node[now].flag=0;
	}
}

//now 目前節點座標
//L,R目前節點包含的範圍
//uL,uR想要更新資料的範圍
//add更新的資料內容 
int add;
void update(int now,int L, int R,int uL,int uR)
{
	if(uL>R||uR<L)return ;
	if(uL<=L&&uR>=R)
	{
		node[now].flag+=add;
		node[now].max+=add;
		node[now].min+=add;
		return;
	}
	pushdown(now);
		
    update(LC,L,M,uL,uR);
   	update(RC,M+1,R,uL,uR);
 
    node[now].max=max(node[LC].max,node[RC].max);
    node[now].min=min(node[LC].min,node[RC].min);
}

int Answer(int N,int P,int *H,int *L,int *R,int *V)
{
    build(1,0,N-1,H);
    for(int i=0;i<P;i++)
    {
    	add=V[i];
        update(1,0,N-1,L[i]-1,R[i]-1);
    }
    return node[1].max-node[1].min;
}
/*int main()
{
	const int maxN = 1000000;
	const int maxP = 1000000;
    int *H = new int[maxN];
    int *L = new int[maxP];
    int *R = new int[maxP];
    int *V = new int[maxP];
    int N,P;
    while( cin>>N>>P )
    {
        for(int i=0;i<N;++i)
            cin>>H[i];
        for(int i=0;i<P;++i)
            cin>>L[i]>>R[i]>>V[i];
        cout<<Answer(N,P,H,L,R,V)<<endl;
    }
}*/
