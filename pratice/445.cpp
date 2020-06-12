#include<iostream>
#include<vector>
using namespace std;
string n;
int K[1<<16],ns;
vector<int> togo;

int toten(string n)
{
	int s=0;
	for(int i=0;i<ns;i++)
		s=(s<<1)+(n[i]-'0');
	return s;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>n;
	ns=n.size();
	togo.emplace_back(toten(n));
	for(int i=1<<ns;i>=0;i--)
		K[i]=1000;
	K[togo[0]]=0;
	for(int i=1;i<=ns;i++)
	{
		int num=(1<<i)-1,togos=togo.size();
		for(int j=i;j<=ns;j++)
		{
			for(int k=0;k<togos;k++)
			{
				int direct=togo[k]^num;
				if(K[direct]==1000)
					togo.emplace_back(direct);
				if(K[togo[k]]+i<K[direct])
					K[direct]=K[togo[k]]+i;
			}
			num<<=1;
		}
	}
	cout<<K[0]<<'\n';
	return 0;
}
