#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	//--(){}[]<>--
	string waves;
	stack<bool> L;
	char k;
	int ans=0;
	while(cin.get(k))
	{
		if(k=='('||k=='{'||k=='['||k=='<')
			waves.append(1,'(');
		else if(k==')'||k=='}'||k==']'||k=='>')
			waves.append(1,')');
		else if(k=='\n')
			break;
	}
	//cout<<waves;
	for(int i=waves.size()-1;i>=0;i--)
	{
		if(waves[i]=='(')L.push(0);
		else
		{
			ans++;
			if(!L.empty())L.pop();
			else break;
		}
	}
	cout<<ans<<'\n';
	return 0;
}

