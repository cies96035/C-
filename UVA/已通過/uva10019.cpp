#include<iostream>
using namespace std;

int M,N,b;
int t[10];

int oneintwocarry(int x)
{
	int one=0;
	while(x)
	{
		if(x&1)
			one+=1;
		x/=2;
	}
	return one;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	//Init
	for(int i=0;i<10;i++)
		t[i]=oneintwocarry(i);
		
	cin>>M;
	while(M--)
	{
		b=0;
		cin>>N;
		cout<<oneintwocarry(N)<<' ';
		while(N)
		{
			b+=t[N%10];
			N/=10;
		}
		cout<<b<<'\n';
	} 
	return 0;
}

