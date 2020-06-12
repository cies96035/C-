#include<iostream>
using namespace std;

int square(int a,int b)
{
	return a*a;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int (*pf)(int,int);
	pf=square;
	cout<<square<<endl;
	cout<<&pf<<endl;
	return 0;
}

