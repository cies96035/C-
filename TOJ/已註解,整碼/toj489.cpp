#include<iostream>
using namespace std;
#define M 200100
typedef long long ll;
ll dp[M],sum[M];//dp[i] 當長度為i時的最佳解，sum[i] 1~i的總和(用來求區段和) 
int ipt;//儲存input 
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int N,K;;
	cin>>N>>K;
	for(int i=1;i<=N;i++)
	{
		cin>>ipt;
		sum[i]=ipt+sum[i-1];
		
		//two choice
		//1.最佳解是從尾取K個+頭前面一格不選
		//2.最佳解等同前面一個長度的最佳解 
		if(i>K)
			dp[i]=max(sum[i]-sum[i-K]+dp[i-K-1],dp[i-1]);
		else if(i==K)
			dp[i]=sum[i]-sum[0];
	}
	cout<<dp[N]<<'\n'; 
	return 0;
}

