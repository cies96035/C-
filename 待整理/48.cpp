#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

char isneed(char k)
{
	if (k=='>'||k==')'||k==']'||k=='}'||k=='<'||k=='('||k=='['||k=='{')
	return 1;
	else return 0;
}

int main()
{
	string a;
	int l=0;
	char k;
	stack<int> c;
	while(cin.get(k))
	{
		if(isneed(k))
		{
			if(k=='>'||k==')'||k==']'||k=='}')
			{
				a+=')';
				l++;
			}
			else
			{
				a+='(';
				l++;
			}
		}
		if(k=='\n')break;
	}
	bool b[l];
	int u=a.find(")(",0);
	while(u!=-1)
	{
		b[u]=b[u+1]=1;
		a.erase(u,2);
		u=a.find(")(",0);
	}
	cout<<a<<endl;
	return 0;
}

