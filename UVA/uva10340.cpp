#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	 
	string s,t;
	while(cin>>s>>t)
	{
		int index=0,ts=t.size(),ss=s.size();
		for(int i=0;i<ts&&index<ss;i++)
			if(s[index]==t[i])index++;
		if(index==ss)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}

