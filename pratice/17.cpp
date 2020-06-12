#include<iostream>
using namespace std;

void shift(int t)
{
		while(t--)cout<<' ';
	return;
}

void p(int a)
{
	int b=0;
	while(a>b)
		cout<<char('A'+b++);
	while(b-->=0)
		cout<<char('B'+b);
	cout<<'\n';
	return;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int T;
	while(cin>>T)
	{
		int i=0,d=T;
		while(i<T)
		{
			shift(--d);
			p(i++);
		}
		T--;
		i--;
		while(d<T)
		{
			shift(++d);
			p(--i);
		}
	}
	return 0;
}

