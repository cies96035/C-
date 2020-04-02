#include<iostream>
using namespace std;

#define LC (2*root)
#define RC (2*root+1)
#define M ((L+R)/2)

struct Node
{
	long long max;
} node[40000000];
long long X[10000000];

//建樹 
void build(int root,int L,int R)
{
	if(L==R)//建到最底層 
	{
		node[root].max=X[L];
	}
	else
	{ 
		build(LC,L,M);
		build(RC,M+1,R);	
		node[root].max=max(node[RC].max,node[LC].max);
	} 
}

int sL,sR;
long long search(int root,int L,int R)
{
	//沒有交集 
	if(sL>R||sR<L)return -2e18;
	//完全包含 
	if(sL<=L&&sR>=R)return node[root].max;
	return max(search(LC,L,M),search(RC,M+1,R));
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int N,Q;
	cin>>N>>Q;
	for(int i=0;i<N;i++)cin>>X[i];
	build(1,0,N-1);
	while(Q--)
	{
		cin>>sL>>sR;
		if(sL>sR)swap(sL,sR);//少這行害我機掰少了16分 
		sL--;
		sR--;
		cout<<search(1,0,N-1)<<'\n';
	}
	return 0;
}

