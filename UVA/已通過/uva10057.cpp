#include<iostream>
#include<algorithm>
using namespace std;

//數學題 

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	 
	int n;
	while(cin>>n)
	{
		int x[n];
		for(int i=0;i<n;i++)cin>>x[i];
		sort(x,x+n);
		if(n%2)//奇數個 
		{
			int mid=x[n/2];
			cout<<mid<<' '<<upper_bound(x,x+n,mid)-lower_bound(x,x+n,mid)<<" 1\n";
		}
		else
		{
			int *mid=&x[n/2];
			cout<<*(mid-1)<<' '<<upper_bound(x,x+n,*mid)-lower_bound(x,x+n,*(mid-1))<<' '<<*mid-*(mid-1)+1<<'\n';
		}
	}
	return 0;
}

