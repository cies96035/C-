#include<iostream>
#include<algorithm> 
using namespace std;

#define Max 10100

int N,K,arr[Max],tmp,Case=1,*tmp2;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin>>N>>K&&N)
	{
		cout<<"CASE# "<<Case++<<":\n";
		for(int i=0;i<N;i++)
			cin>>arr[i];
		sort(arr,arr+N);
		while(K--)
		{
			cin>>tmp;
			tmp2=lower_bound(arr,arr+N,tmp);
			if(*tmp2==tmp)
				cout<<tmp<<" found at "<<tmp2-arr+1<<'\n';
			else
				cout<<tmp<<" not found\n";
		}
	}
	return 0;
}

