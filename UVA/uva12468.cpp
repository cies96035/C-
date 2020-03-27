#include<iostream>
using namespace std;

int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		if(a==-1&&b==-1)break;
		int c=abs(a-b);
		cout<<(c>50?100-c:c)<<endl;
	}
	return 0;
}

