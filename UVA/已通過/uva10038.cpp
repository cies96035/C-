#include<iostream>
#include<cstring>
using namespace std;


int main()
{
	int n,a,b;
	while(cin>>n>>a)
	{
		if(n==1)
		{
			cout<<"Jolly"<<endl;
			continue;
		}
		bool used[n];
		memset(used,0,sizeof(used));
		for(int i=1;i<n;i++)
		{
			cin>>b;
			used[abs(b-a)]=1;
			a=b;
		}
		for(int i=1;i<n;i++)
		{
			if(!used[i])
			{
				cout<<"Not jolly"<<endl;
				break;
			}
			if(i==n-1)
				cout<<"Jolly"<<endl;
		}
	}
	return 0;
}

