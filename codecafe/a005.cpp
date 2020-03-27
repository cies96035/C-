#include<iostream>
using namespace std;

typedef long long ll;

#define N 1010
bool isntprime[N];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	isntprime[0]=isntprime[1]=1;
	for(int i=4;i<N;i+=2)
		isntprime[i]=1;
	for(int i=2;i<N;i++)
	{
		if(!isntprime[i]) 
		{
			for(int j=i*i,k=i+i;j<N;j+=k)
				isntprime[j]=1;
		}
	} 
	
	int n;
	cin>>n;
	cout<<(isntprime[n]?"NO":"YES")<<'\n';
	return 0;
}

