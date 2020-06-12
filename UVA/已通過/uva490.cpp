#include<iostream>
using namespace std;
#define Max 110
string a[Max];
int index=0;
size_t L=0;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(getline(cin,a[index]))
		L=max(a[index++].size(),L);
	
	for(int i=0;i<L;i++)
	{
		for(int j=index-1;j>=0;j--)
			if(i<a[j].size())
				cout<<a[j][i];
			else
				cout<<' ';
		cout<<'\n';
	}
	return 0;
}

