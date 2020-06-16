#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

#define MaxN 55

int gcd(int a,int b)
{
	while((a%=b)&&(b%=a));
	return a+b;
}

int N,value[MaxN];
long double fraction;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cout<<fixed<<setprecision(6);

	while(cin>>N&&N)
	{
		fraction=0;
		for(int i=0;i<N;i++)
		{
			cin>>value[i];
			for(int j=0;j<i;j++)
				if(gcd(value[i],value[j])==1)
					fraction++;
		}
		
		if(fraction)
			cout<<sqrt(6.0/fraction*(N*N-N)/2.0)<<'\n';
		else
			cout<<"No estimate for this data set.\n";
	}
	return 0;
}

