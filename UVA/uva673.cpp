#include<iostream>
#include<stack>
using namespace std;
int t;
string Q;

bool isbalance(string q)
{
	stack<bool> s;
	for(int i=0;i<q.size();i++)
	{
		if(q[i]=='(')
			s.push(0);
		else if(q[i]==')')
		{
			if(s.empty()||s.top()!=0)
				return false;
			s.pop();
		}
		else if(q[i]=='[')
			s.push(1);
		else if(q[i]==']')
		{	
			if(s.empty()||s.top()!=1)
				return false;
			s.pop();
		}
	}
	if(s.empty())
		return true;
	else
		return false;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>t;
	cin.ignore();
	while(t--)
	{	
		getline(cin,Q);
		if(isbalance(Q))
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}

