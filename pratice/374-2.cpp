#include<iostream>
#include<algorithm>
using namespace std;
const int maxN=100010;
int N,K,Sum,w[maxN],Mid,Max=0,Min=1,val;

int R(int num)
{
	int sum=0,a=0,b=0,e=0;
	while(sum<num)
		sum+=w[b++];
	e+=N-b+1;
	while(b<N||num<sum)
	{
		sum-=w[a++];
		while(sum<num&&b<N)
			sum+=w[b++];
		if(!(sum<num))
			e+=N-b+1;
	}
	return e;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>N>>K;
	for(int i=0;i<N;i++)
	{
		cin>>w[i];
		Max+=w[i];
	}
	
	//for(int i=Max;i>0;i--)
	//	cout<<i<<' '<<R(i)<<endl;
	while(Min<=Max)
	{
		Mid=(Max+Min)/2;
		val=R(Mid);
		if(val>K)Min=Mid+1;
		else if(val<K) Max=Mid-1;
		else break;
	} 
	if(R(Mid)<K)cout<<Mid-1<<endl;
	else if(K==1)cout<<Max<<endl;
	else
	{
		while(R(Mid+1)==R(Mid))Mid++;
		cout<<Mid<<endl;
	}
	return 0;
}
