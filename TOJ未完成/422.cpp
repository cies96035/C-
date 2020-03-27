#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int N;
	cin>>N;
	int input,front_sum[N+1];
	long long front_min[N];
	front_sum[0]=0;
	for(int i=0;i<N;i++)
	{
		cin>>input;
		front_sum[i+1]=front_sum[i]+input;
	}
	for(int i=0;i<N;i++)//計算前i個的最小值 
	{
		long long sum=front_sum[i+1]-front_sum[0];
		front_min[i]=sum*sum;
		for(int j=1;j<=i;j++)
		{
			sum=(front_sum[i+1]-front_sum[j]);
			front_min[i]=min( front_min[i] , front_min[j-1]+sum*sum );
		}
	}
	cout<<front_min[N-1]<<'\n';
	return 0;
}

