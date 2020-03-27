#include<iostream>
#include<vector>
using namespace std;
//效能應該不高，但不至於TLE...吧? 

typedef long long ll;

#define N 100010
bool isntprime[N];
vector<int> P[N];
string str;

bool check()
{
	for(int i=0;i<P[str.size()].size();i++)
	{
		int k=str.size()/P[str.size()][i],j=k;
		string sub=str.substr(0,k);
		for(j;j<str.size();j+=k)
			if(sub!=str.substr(j,k))
				break;
		if(j>=str.size())
		{
			for(int i=1;i<sub.size();i++)
				if(sub[i]!=sub[0])return true;
			return false;
		}
	}
	return false;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	//pre 
	int T;
	cin>>T;
		
	for(ll i=2;i<N;i++)
	{
		if(!isntprime[i]) 
		{
			for(ll j=i+i;j<N;j+=i)
			{
				isntprime[j]=1;
				P[j].push_back(i);
			}
		}
	} 
	
	while(T--)
	{
		cin>>str;
		cout<<(check()?"ACCEPTED\n":"WRONG ANSWER\n");
	}
	
	return 0;
}

