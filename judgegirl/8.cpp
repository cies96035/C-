#include<iostream>
using namespace std;

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a<b)swap(a,b);
	if(a<c)swap(a,c);
	if(a<b+c)cout<<1<<endl;
	else cout<<0<<endl;
	return 0;
}

