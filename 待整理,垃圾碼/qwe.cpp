#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int N,P,C;
	cin>>N>>P>>C;
	bool k[30],flag=0;
	int tree[P];
	memset(tree,0,sizeof(tree));
	memset(k,0,sizeof(k));
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<P;j++)
		{
			int t;
			cin>>t;
			tree[j]+=t;
		}
	}
	for(int i=0;i<P;i++)
	{
		int t=tree[i],u=0;
		while(t)
		{
			if(t%2)
			{
				if(k[u]==0)k[u]=1;
				else k[u]=0;
			}
			t/=2;
			u++;
		}
	}
	for(int i=0;i<10;i++)if(k[i]==1)flag=1;
	
	if(flag==1&&C==0||flag==0&&C==1)
		cout<<"Holly Win!"<<endl;
	else
		cout<<"Ivy Win!"<<endl;
		
	
	return 0;
}

