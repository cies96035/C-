#include<iostream>
#include<cmath>
using namespace std;


/*
when the amount of n's factor is even
the light is still off
else the light is on

if n=p1^k1*p2^k2...  (p->prime number)
n's factor amounts is (k1+1)*(k2+1)*(k3+1)...
if k1,k2,k3... are all even the amounts is odd,and also n is one integer's square
else the amounts is even

*/
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	unsigned int n;
	while(cin>>n&&n)
	{
		if(pow(int(pow(n,0.5)),2)==n)//if n is a square number
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
	return 0;
}

