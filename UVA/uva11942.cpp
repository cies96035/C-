#include<iostream>
using namespace std;

int t,Max,Min,num;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cout<<"Lumberjacks:\n";
	
	cin>>t;
	while(t--)
	{
		Max=-2e9;
		Min=-Max; 
		for(int i=0;i<10;i++)
		{
			cin>>num;
			if(num>Max)
				Max=num;
			else
				Max=2e9;
			if(num<Min)
				Min=num;
			else
				Min=-2e9;
		}
		if(Max==2e9&&Min==-2e9)
			cout<<"Unordered\n";
		else
			cout<<"Ordered\n";
	}
	return 0;
}

