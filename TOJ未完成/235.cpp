#include<iostream>
#include<vector> 
using namespace std;

const int N=46341;//搜到46341以下的質數sqrt(max_int)
bool isntprime[N];
vector<int> prime;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	for(int i=2;i<N;i+=2)isntprime[i]=1;
	prime.push_back(4);
	for(int i=3;i<N;i+=2)
	{
		if(!isntprime[i])
		{
			prime.push_back(i*i);
			for(int j=i*i,k=i+i;j<N;j+=k)
			{
				if(!isntprime[j])
					isntprime[j]=1;
			}
		}
	}
	int T,start,end;
	cin>>T;
	while(T--)
	{
		int ans=0;
		cin>>start>>end;
		for(;start<=end;start++)
		{
			int i=0;
			for(;i<prime.size();i++)
			{
				if(!(start%prime[i]))
					break;
			}
			if(i==prime.size())
				ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

