#include <iostream>
/*
a b *  1 2
c d    3 4
a1+b3 a2+b4
c1+d3 c2+d4

a b * 1
c d   2
a1+b2
c1+d2
靠背為了這題活生生學了一整個矩陣，明明數學都還沒學到 
有夠虧 
*/


using namespace std;
const int mod=1000000009;

struct matrix
{
	long long a,b,c,d;
};

void F(long long n)
{
	matrix 
	base={1,1,1,0},
	ans={1,1,1,1};
	while(n)
	{
		long long bA=base.a,bB=base.b,bC=base.c,bD=base.d,
		aA=ans.a,aB=ans.b,aC=ans.c,aD=ans.d;
		if(n%2)
		{
			ans.a=bA*aA+bB*aC;
			ans.b=bA*aB+bB*aD;
			ans.c=bC*aA+bD*aC;
			ans.d=bC*aB+bD*aD;
			if(ans.a>=mod)ans.a%=mod;
			if(ans.b>=mod)ans.b%=mod;
			if(ans.c>=mod)ans.c%=mod;
			if(ans.d>=mod)ans.d%=mod;
		}
		base.a=bA*bA+bB*bC;
		base.b=bA*bB+bB*bD;
		base.c=bC*bA+bD*bC;
		base.d=bC*bB+bD*bD;
		if(base.a>=mod)base.a%=mod;
		if(base.b>=mod)base.b%=mod;
		if(base.c>=mod)base.c%=mod;
		if(base.d>=mod)base.d%=mod;
		n/=2;
	}
	cout<<ans.c-1<<endl;
}

int main() {
    long long i;
    while(cin>>i) 
    {
    	F(i+1);
    }
    return 0;
}
