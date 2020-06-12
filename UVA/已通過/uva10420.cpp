#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int n;
string str;
map<string,int> amount;
vector<string> K;

bool cmp(string a,string b)
{
	return a<b;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>n;
	while(n--)
	{
		cin>>str;
		cin.ignore();
		if(amount.find(str)==amount.end())
		{
			K.emplace_back(str);
			amount[str]=1;
		}
		else
			amount[str]++;
		getline(cin,str);
	}
	
	sort(K.begin(),K.end(),cmp);
	
	for(int i=0;i<K.size();i++)
		cout<<K[i]<<' '<<amount[K[i]]<<'\n';
	return 0;
}

