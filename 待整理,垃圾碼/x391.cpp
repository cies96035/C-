#include<iostream>
using namespace std;

const int maxNode = 1000000;

//左子節點和右子節點的座標位置 
#define LC (now*2)
#define RC (now*2+1) 
#define M (L+R)/2

struct Node
{
    int max,flag;
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
        node[now].max=H[L];
        return;
    }
    //若並非最底層，建構底下的左右兩層線段樹
    //一個節點分成兩半
    //分別為L到M(左節點)，M+1到R(右節點) 
    build(LC,L,M,H);
    build(RC,M+1,R,H);
    
    //紀錄此節點左右兩子節點的最大和最小值 
    node[now].max=max(node[LC].max,node[RC].max);
}

int x,v,K;
//待理解 
void pushdown(int now)
{
	if(node[now].flag)
	{    
	int k=node[now].flag;
		if(K==1)
		{
		    node[LC].flag=node[RC].flag=k;
		    node[LC].max+=k;
		    node[RC].max+=k;
		}
		else
		{
		    node[LC].flag=node[RC].flag=k;
		    node[LC].max%=k;
		    node[RC].max%=k;
		}
		node[now].flag=0;
	}
}

//now 目前節點座標
//L,R目前節點包含的範圍
//uL,uR想要更新資料的範圍
//add更新的資料內容 
void update(int now,int L, int R,int uL,int uR)
{
	
	/*cout<<"   "<<node[1].max<<'\n'
	<<" "<<node[2].max<<"   "<<node[3].max<<'\n'
	<<node[4].max<<' '<<node[5].max<<' '<<node[6].max<<' '<<node[7].max<<'\n';
	cout<<"   "<<node[1].flag<<'\n'
	<<" "<<node[2].flag<<"   "<<node[3].flag<<'\n'
	<<node[4].flag<<' '<<node[5].flag<<' '<<node[6].flag<<' '<<node[7].flag<<"\n\n";
	*/
    if(uL>R||uR<L)return ;
    if(uL<=L&&uR>=R)
    {
        if(K==1)
        {
            node[now].flag=x;
            node[now].max+=x;
        }
        else
        {
            node[now].flag=v;
            node[now].max=max(node[LC].max%v,node[RC].max%v);
        }
        return;
    }
    pushdown(now);
        
    update(LC,L,M,uL,uR);
    update(RC,M+1,R,uL,uR);
 
    node[now].max=max(node[LC].max,node[RC].max);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int N,T;
    cin>>N;
    int H[N];
    for(int i=0;i<N;i++)cin>>H[i];
    build(1,0,N-1,H);
    cin>>T;
    while(T--)
    {
        cin>>K;
        if(K==1)
        {
            int i;
            cin>>x>>i;
            update(1,0,N-1,i,i);
        }
        else if(K==2)
        {
            int L,R;
            cin>>L>>R>>v;
            update(1,0,N-1,L,R);
        }
        else
        {	
		    cout<<node[1].max<<'\n';
        }
    }
}
