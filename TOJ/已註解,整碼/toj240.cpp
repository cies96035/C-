#include<iostream>
#include<cmath>
using namespace std;

//結果mod 1000000007 
#define mod 1000000007

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	//數字大要用ull儲存(沒有負數
	unsigned long long X,N,ans=0;
	cin>>X>>N;
	//輸入觸手能量，並調整，多觸手跟少觸手比較
	unsigned long long A[N];
	/*
	如果少觸手的CP值比較高，更新多觸手的值
	寫法直覺可以更快，只是反正數字不大
	慢慢算就好
	*/ 
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
		for(int j=0;j<i;j++)
		{
			unsigned long long num=pow(2,i-j);
			//如果少觸手CP值高，則更新多觸手值
			if(A[j]*num<A[i])
				A[i]=A[j]*num;
		}
		A[i]%=mod;
	}
	
	//優先用多觸手，再慢慢用到少觸手 
	for(int i=N-1;i>=0;i--)
	{
		unsigned long long num=pow(2,i);
		if(X>=num)
		{
			unsigned long long p=X/num;
			X-=p*num;
			//**注意**
			//沒有p%mod，ans會溢位 
			p%=mod;
			ans+=p*A[i];
			ans%=mod;
			if(X==0)break;
		}
	}
	cout<<ans<<endl;
	return 0;
}

