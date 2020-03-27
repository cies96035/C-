#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

struct water
{
	long long x,y;
};
bool cmp(const water &a,const water &b)
{
	if(a.y>b.y)return 1;
	else return 0;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0); 
	
	int K,a[5],N;
	cin>>K;
	for(int i=0;i<5;i++)cin>>a[i];
	cin>>N;
	water W[N];
	for(int i=0;i<N;i++)
	{
		cin>>W[i].x>>W[i].y;
	}
	for(int i=0;i<N;i++)
	{
		long long ans=0,k=W[i].x;
		for(int j=0;j<5;j++)
		{
			ans+=pow(k,N-j)*a[j];
		}
		W[i].y-=ans;
	}
	sort(W,W+N,cmp);
	cout<<W[K-1].y<<endl;
	return 0;
}

