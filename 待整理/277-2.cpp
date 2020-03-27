#include<iostream>
using namespace std;

string ans(string n)
{
	int ns=n.size()/2,s=ns-1;
	if(n.size()%2==0)//偶數 
	{
		/*
		從最中間開始
		00~10變成11,11~21變成22 依此類推
		99變成00
		*/
		while(n[s]=='9'&&n[ns]=='9')
		{
			n[s]=n[ns]='0';
			s--;
			ns++;
		}
		if(n[s]<'9'||n[ns]<'9')//沒進位狀況 
		{
			if(n[s]>n[ns])n[ns]=n[s];
			else n[ns]=n[s]=n[s]+1;
			while(s)
			{
				s--;
				ns++;
				n[ns]=n[s];
			}
		}
	}
	else
	{
	}
	return n;
}

int main()
{
	string num;
	int n;
	cin>>n;
	while(n--)
	{
		cin>>num;
		cout<<ans(num)<<endl;
	}
	
	return 0;
}

