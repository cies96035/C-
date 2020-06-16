#include<iostream>
using namespace std;

int T,N,K,P,Case=1;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>T;
	while(T--)
	{
		cin>>N>>K>>P;
		P%=N;//next P person
		K+=P;
		
		//if K<=N than output K else output K-N
		if(K>N)
			K-=N;
		cout<<"Case "<<Case++<<": "<<K<<'\n';
	}
	return 0;
}

