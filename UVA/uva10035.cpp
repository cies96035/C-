#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int a,b;
	while(cin>>a>>b)
	{
		int count=0,carry=0;
		if(a==0&&b==0)break;
		while(a||b)
		{
			if(a%10+b%10+carry>=10)
			{
				count++;
				carry=1;
			}
			else
				carry=0;
			a/=10;
			b/=10;
		}
		if(count==0)cout<<"No carry operation."<<endl;
		else if(count==1)cout<<"1 carry operation."<<endl;
		else cout<<count<<" carry operations."<<endl;
	}
	return 0;
}

