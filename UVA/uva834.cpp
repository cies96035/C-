#include<iostream>
#include<queue>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0); 
	
	int n,m;
	while(cin>>n>>m)
	{
		queue<int> nums;
		while(m)
		{
			nums.push(n/m);
			n%=m;
			swap(n,m);
		}
		cout<<'['<<nums.front();
		nums.pop();
		if(!nums.empty())cout<<';';
		while(!nums.empty())
		{
			cout<<nums.front();
			nums.pop();
			if(!nums.empty())cout<<',';
		}
		cout<<"]\n";
	}
	return 0;
}

