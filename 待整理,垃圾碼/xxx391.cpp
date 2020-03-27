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

//now 目前節點座標
//L,R目前節點包含的範圍
//uL,uR想要更新資料的範圍
//add更新的資料內容 
int x,v,K;
void update(int now,int L, int R,int t)
{
    if (L == R)
    {
        if(t==L&&K==1)
        {    
            node[now].max += x;
        }
        else if(t==L)
        {
            node[now].max %= v;
		}
        return;
    }
 
    if (t<=M) update(LC,L,M,t);
    else update(RC,M+1,R,t);
 
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
			update(1,0,N-1,i);
		}
		else if(K==2)
		{
			int L,R;
			cin>>L>>R>>v;
			for(int i=L;i<=R;i++)
			{
				update(1,0,N-1,i);
			}
		}
		else
		{
			cout<<node[1].max<<'\n';
		}
	}
}
