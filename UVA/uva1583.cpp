#include<iostream>
#include<cstring>
using namespace std;

#define maxn 100005
int unit[maxn];
 
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	for(int i=1;i<maxn;i++)
	{
		int num=i,k=num;
		while(num>0)
		{
			k+=num%10;
			num/=10;
		}
		if(!unit[k])unit[k]=i;
	}
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		cout<<unit[N]<<'\n';
	}
	return 0;
}

