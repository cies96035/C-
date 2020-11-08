#include<iostream>
#include<cstring>
using namespace std;

bool can_pal(int *c)
{
	bool odd=0;
	for(int i=0;i<26;i++)
		if(c[i]%2)
		{
			if(odd==1)
				return 0;
			odd++;
		}
	return 1;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	char k;
	int s[26]={0};
	while(cin.get(k))
	{
		if('a'<=k && k<='z')
			s[k-'a']++;
		else if('A'<=k && k<='Z')
			s[k-'A']++;
		else if(k=='\n')
		{
			if(can_pal(s))
				cout<<"yes !\n";
			else
				cout<<"no...\n";
			memset(s,0,sizeof(s));
		}
	}
	if(can_pal(s))
		cout<<"yes !\n";
	else
		cout<<"no...\n";
	return 0;
}
