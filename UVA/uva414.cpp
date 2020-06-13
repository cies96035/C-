#include<iostream>
using namespace std;

#define MaxN 15

string s;
int N,ans,Max,num;

int cnt_X_amounts(string x)
{
	int amount=0;
	for(int i=0;i<x.size();i++)
		if(x[i]=='X')
			amount++;
	return amount;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	while(cin>>N&&N)
	{
		Max=0;
		ans=0;
		cin.ignore();
		
		for(int i=0;i<N;i++)
		{
			getline(cin,s);
			num=cnt_X_amounts(s);
			if(num>Max)
				Max=num;
			ans-=num;
		}
		
		ans+=Max*N;
		cout<<ans<<'\n';
	}
	return 0;
}

