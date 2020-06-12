#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cout<<fixed<<setprecision(2);
	int t;
	long double C,d;
	cin>>t;
	for(int Case=1;Case<=t;Case++)
	{
		cin>>C>>d;
		cout<<"Case "<<Case<<": "<<(C*9/5+32+d-32)*5/9<<'\n';
	}
	return 0;
}
