#include<iostream>
using namespace std;

int main()
{
	
	int N,M;
	cin>>N>>M;
	int K,b[N],dp1[N+1]={0},dp2[N+1]={0};//dp1放dp2空 
	//for(int i=0;i<N;i++)
	//	cin>>b[i];
	
	//part1
	for(int i=0;i<N;i++)
	{
		int sum=0,max=0;
		for(int j=0;j<M;j++)
		{
			cin>>K;
			sum+=K;
			if(sum>max)max=sum;
			if(sum<0)sum=0;
		}
		b[i]=max;
	} 

	
	//part2
	dp1[0]=b[0];//先吃第一列 
	for(int i=1;i<N;i++)
	{
		dp1[i]=dp2[i-1]+b[i];
		dp2[i]=max(dp1[i-1],dp2[i-1]);
	}
	cout<<max(dp1[N-1],dp2[N-1])<<'\n';
	return 0;
}

