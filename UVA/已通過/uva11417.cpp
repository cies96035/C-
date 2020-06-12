#include<iostream>
using namespace std;

#define Max 510

int GCD[Max][Max],n,sum;

inline int gcd(int a,int b)
{
	while((a%=b)&&(b%=a));
	return a+b;
}

void Init()
{
	for(int i=1;i<Max;i++)
		for(int j=i+1;j<Max;j++)
			GCD[i][j]=gcd(i,j);
	return;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	Init();
	
	while(cin>>n&&n)
	{
		sum=0;
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				sum+=GCD[i][j];
		cout<<sum<<'\n';
	}
	return 0;
}


