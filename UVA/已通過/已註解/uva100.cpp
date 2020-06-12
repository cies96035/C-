//3n+1 problem
//just force 

#include<iostream>
using namespace std;
int main()
{
	int i,j,ans;
	while(cin>>i>>j)
	{
		ans=0;
		cout<<i<<' '<<j<<' ';
		if(i>j)swap(i,j);
		for(int ii=i;ii<=j;ii++)
		{
			int count=1,n=ii;
			while(n!=1)
			{
				if(n%2)n=3*n+1;
				else n/=2;
				count++;
			}
			ans=max(count,ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}

