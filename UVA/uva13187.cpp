#include<iostream>
using namespace std;

/*
�ƾ��D 
���D�N�i�osqrt(n+1)-sqrt(1)=S
�A�o��(S+1)^2-1=n
*/ 
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	long long t,S;
	cin>>t;
	while(t--)
	{
		cin>>S;
		cout<<(++S)*S-1<<endl;
	}
	return 0;
}

