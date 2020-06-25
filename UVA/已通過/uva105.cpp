#include<iostream>
using namespace std;

/*
5000*10000
can force
*/ 
#define Max 10100
int L,H,R,skyline[Max],MaxR;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin>>L>>H>>R)
	{
		for(int i=L;i<R;i++)
			if(H>skyline[i])
				skyline[i]=H;
		if(R>MaxR)
			MaxR=R;
	}
	for(int i=1;i<MaxR;i++)
		if(skyline[i-1]!=skyline[i])
			cout<<i<<' '<<skyline[i]<<' ';
	cout<<MaxR<<" 0\n";
	return 0;
}
