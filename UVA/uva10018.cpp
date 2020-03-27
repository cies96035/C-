#include<iostream>
using namespace std;


unsigned int reverse(unsigned int x)
{
	unsigned int toreturn=0;
	while(x)
	{
		toreturn=x%10+toreturn*10;
		x/=10;
	}
	return toreturn;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int N;
	cin>>N;
	while(N--)
	{
		unsigned int count=0,r,P;
		cin>>P;
		r=reverse(P);
		do{
			count++;
			P+=r;
			r=reverse(P);
		}while(r!=P);
		cout<<count<<' '<<r<<endl;
	}
	return 0;
}

