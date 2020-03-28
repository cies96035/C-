#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int M=1000000;
bool isntprime[M];//篩法用 
vector<int> prime;//紀錄質數

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	
	//篩法:紀錄質數 
	prime.push_back(2);
	for(int i=3;i<M;i+=2)
	{
		if(!isntprime[i])
		{
			for(int j=i,k=i+i;j<M;j+=k)
			{
				if(!isntprime[j])
					isntprime[j]=1;
			}
			prime.push_back(i);
		}
	}
	
	int A,B;
	while(cin>>A>>B)
	{
		if(A>B)swap(A,B);//A<=B
		long long num=1,ans;
		
		for(int i=A+1;i<=B;i++)
			num*=i;
		num++;
		
		//num=B!/A!+1
		ans=upper_bound(prime.begin(),prime.end(),A)-prime.begin();
		//ans=A!質因數數量=小於A的質數數量
		//cout<<ans<<endl;
		
		for(int i=0,Ans=ans;i<prime.size();i++)
		{
			if(!(num%prime[i]))
			{
				if(i>=Ans)
					ans++;
				while(!(num%prime[i]))num/=prime[i];
			}
		}
		//ans+=num質因數數量->一一測試(範圍:比A大的質數，避免重複計算質因數) 
		
		 
		if(num!=1)ans++;
		/*
		M=6
		1 3->
		ans=0->1之前沒質數 
		2*3+1=7沒被檢查到<M的質數 
		確定7是質數，ans+1
		ans=1 
		*/
		
		
		cout<<ans<<'\n';
		//輸出 
	}
	return 0;
}
 
