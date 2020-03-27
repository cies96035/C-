#include<iostream>
using namespace std;

int volunteer[10000+10];

int main()
{
	int n,R,cnt=1,people;
	while(cin>>n>>R)
	{
		if(n==R)
			cout<<'*';
		while(R--)
		{
			cin>>people;
			volunteer[people]=cnt;
		}
		for(int i=1;i<=n;i++)
			if(volunteer[i]!=cnt)cout<<i<<' ';
		cout<<endl;
		cnt++;
	}
	return 0;
}

