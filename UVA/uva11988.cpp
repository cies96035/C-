#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	char k;
	string word,ans;
	bool where=0;
	while(cin.get(k))
	{
		if(k=='[')
		{
			if(!where)
				ans.insert(0,word);
			else
			{
				ans.append(word);
				where=0;
			}
			word.clear();
		}
		else if(k==']')
		{
			if(!where)
			{
				ans.insert(0,word);
				where=1;
			}
			else
				ans.append(word);
			word.clear();
		}
		else if(k=='\n')
		{
			if(!where)
				ans.insert(0,word);
			else
				ans.append(word);
			cout<<ans<<'\n';
			ans.clear();
			word.clear();
		}
		else
			word.append(&k,1);
	}
	return 0;
}

