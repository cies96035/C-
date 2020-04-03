#include<iostream>
using namespace std;

/*
數學題 
依題意可得sqrt(n+1)-sqrt(1)=S
再得到(S+1)^2-1=n
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

