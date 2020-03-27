#include<iostream>
#include<cmath> 
#include<iomanip>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cout<<fixed<<setprecision(0);
	long double num,k;
	while(cin>>k>>num)
		cout<<pow(num,1/k)<<'\n';
	return 0;
}

