#include<iostream>
#include<queue>
using namespace std;

queue<int> odd,even;

void OPT(queue<int> o)
{
	while(!o.empty())
	{
		cout<<o.front();
		o.pop();
		if(o.empty())cout<<endl;
		else cout<<' ';
	}
	return;
}

int main()
{
	int n,ipt;
	cin>>n;
	while(n--)
	{
		cin>>ipt;
		if(ipt%2)odd.push(ipt);
		else even.push(ipt);
	}
	OPT(odd);
	OPT(even);
	
	return 0;
}

