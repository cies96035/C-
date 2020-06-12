#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n,set=1;
	while(cin>>n)
	{
		if(n==0)break;
		int average=0,num[n],ans=0;
		for(int i=0;i<n;i++)
		{
			cin>>num[i];
			average+=num[i];
		}
		average/=n;
		for(int i=0;i<n;i++)
			if(num[i]>average)ans+=num[i]-average;
		cout<<"Set #"<<set<<"\nThe minimum number of moves is "<<ans<<".\n\n";
		set++;
	}
	return 0;
}

