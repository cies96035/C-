#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int M=1000000;
bool isntprime[M];//�z�k�� 
vector<int> prime;//�������

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	
	//�z�k:������� 
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
		//ans=A!��]�Ƽƶq=�p��A����Ƽƶq
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
		//ans+=num��]�Ƽƶq->�@�@����(�d��:��A�j����ơA�קK���ƭp���]��) 
		
		 
		if(num!=1)ans++;
		/*
		M=6
		1 3->
		ans=0->1���e�S��� 
		2*3+1=7�S�Q�ˬd��<M����� 
		�T�w7�O��ơAans+1
		ans=1 
		*/
		
		
		cout<<ans<<'\n';
		//��X 
	}
	return 0;
}
 
