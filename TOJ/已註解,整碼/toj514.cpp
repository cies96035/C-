#include<iostream>
using namespace std;

//force

#define d(x) x/1000
#define h(x) x/100%10
#define t(x) x/10%10
#define o(x) x%10

#define P(p) d!=h && d>h == p
#define Q(q) h!=t && h>t == q
#define R(r) t!=o && t>o == r

bool p,q,r;
int d,h,t,o;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>p>>q>>r;
	for(int i=1000;i<10000;i++)
	{
		d=d(i);
		h=h(i);
		t=t(i);
		o=o(i);
		if(P(p)&&Q(q)&&R(r))
			cout<<i<<'\n';
	}
	return 0;
}

