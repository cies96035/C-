#include<iostream>
using namespace std;

int main()
{
	int x;
	cin>>x;
	if(!(x%15)&&x%7)cout<<0<<endl;
	else cout<<1<<endl;
	return 0;
}

