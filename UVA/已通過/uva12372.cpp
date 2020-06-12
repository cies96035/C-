#include<iostream>
using namespace std;

#define N 20
bool isgood(int a,int b,int c)
{
	if(a>N||b>N||c>N)
		return false;
	return true;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int t,a,b,c;
	cin>>t;
	for(int Case=1;Case<=t;Case++)
	{
		cin>>a>>b>>c;
		if(isgood(a,b,c))
			cout<<"Case "<<Case<<": good\n";
		else
			cout<<"Case "<<Case<<": bad\n";
	}
	return 0;
}

