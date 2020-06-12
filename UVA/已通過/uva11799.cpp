#include<iostream>
using namespace std;

int t,Max,N,tmp;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>t;
	for(int Case=1;Case<=t;Case++)
	{
		Max=0;
		cin>>N;
		while(N--)
		{
			cin>>tmp;
				if(tmp>Max)Max=tmp;
		}
		cout<<"Case "<<Case<<": "<<Max<<"\n";
	}
	return 0;
}

