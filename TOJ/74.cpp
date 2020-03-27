#include<iostream>
#include<cstring> 
#include<vector>
using namespace std;

vector<int> prime;

void Initprime()
{
	const int N=7072;//質數範圍(sqrt(5*10^7)) 
	bool isntprime[N]={0};
	for(int i=4;i<N;i+=2)isntprime[i]=1;
	prime.push_back(2);
	for(int i=3;i<N;i+=2)
	{
		if(!isntprime[i])
		{
			for(int j=i*i,k=i+i;j<N;j+=k)
			{
				if(!isntprime[j])
				isntprime[j]=1;
			}
			prime.push_back(i);
		}
	}
	return;
}

string same(string s,int k)//判斷s切k段相不相同 
{
	k=s.size()/k;
	string sub=s.substr(0,k);
	for(int i=k;i<s.size();i+=k)
	{
		string tocmp=s.substr(i,k);
		if(sub!=tocmp)return "";
	}
	return sub;
}
string getans(string necklace)
{
	vector<int> necklace_prime;
	int sum=1,getbigprime=necklace.size();
	
	for(int i=0;i<prime.size();i++)
	{
		if(!(necklace.size()%prime[i]))
		{
			string s=necklace;
			int k=prime[i];
			while(!(s.size()%k)&&(s=same(s,k))!="")
				sum*=k;
			while(!(getbigprime%prime[i]))getbigprime/=prime[i];
		}
	}
	if(getbigprime!=1)
	{
		string s=necklace;
		int k=getbigprime;
		while(!(s.size()%k)&&(s=same(s,k))!="")
			sum*=k;
	}
	return necklace.substr(0,necklace.size()/sum);
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	Initprime();
	string input;
	while(cin>>input)
		cout<<getans(input)<<'\n';
	return 0;
}

