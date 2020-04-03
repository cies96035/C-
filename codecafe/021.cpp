#include<iostream>
using namespace std;

#define SP 1000 //可能取350就好，保險起見取1000 
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int T;
	cin>>T;
	int coin[7]={1000,500,100,50,35,5,1};
	int sp[SP]={0};
	
	for(int i=1;i<SP;i++)
	{
		int Min=sp[i-coin[6]]+1;
		for(int j=1;j<6;j++)
			if(i>=coin[j]&&sp[i-coin[j]]+1<Min)
				Min=sp[i-coin[j]]+1;
		sp[i]=Min;
	}
	
	while(T--)
	{
		int N=0,sum=0,k;
		cin>>N;
		k=N/coin[0];
		sum+=k;
		N-=k*coin[0];
		cout<<sum+sp[N]<<'\n';
	}
	//好煩 
	return 0;
}

