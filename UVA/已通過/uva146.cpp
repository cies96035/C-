#include<iostream>
using namespace std;

string s;
int i;

int unsuccessor()
{
	for(int i=s.size()-2;i>=0;i--)
		if(s[i]<s[i+1])
			return i; 
	return -1;
}
void swapij(int i)
{
	for(int j=s.size()-1;j>i;j--)
		if(s[j]>s[i])
		{
			swap(s[i],s[j]); 
			return;
		}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin>>s&&s!="#")
	{
		i=unsuccessor();
		swapij(i);
		if(i==-1)
			cout<<"No Successor\n";
		else
		{
			cout<<s.substr(0,i+1);
			for(int k=s.size()-1;k>i;k--)
				cout<<s[k];
			cout<<'\n';
		}
	}
	return 0;
}

