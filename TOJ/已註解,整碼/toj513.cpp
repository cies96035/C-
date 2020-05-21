#include<iostream>
using namespace std;

//record a time
struct CLOCK
{
	int h;
	int m;
}a,b,c={24,00};

//if A earlier than B
bool clockcompare(CLOCK A,CLOCK B)
{
	if(A.h!=B.h)return A.h<B.h;
	return A.m<B.m;
}

//two times' delta
CLOCK dclock(CLOCK A,CLOCK B)
{
	CLOCK C;
	//make A bigger than B
	if(clockcompare(A,B))
		swap(A,B);
	C.m=A.m-B.m;
	C.h=A.h-B.h;
	if(C.m<0)
	{
		C.m+=60;
		C.h-=1;
	}
	return C;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>a.h>>a.m>>b.h>>b.m;
	
	//if(b<a) than they cross differant days
	if(clockcompare(b,a))
		c=dclock(c,dclock(a,b));
	else
		c=dclock(a,b);
		
	cout<<"totally "<<c.h<<" hours and "<<c.m<<" minutes."<<'\n';
	return 0;
}

