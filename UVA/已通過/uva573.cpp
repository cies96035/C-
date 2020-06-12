#include<iostream>
using namespace std;

double H,U,D,F,h,f,day;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin>>H>>U>>D>>F&&H)
	{
		h=0;
		day=1;
		f=U*F/100;
		while(h>=0)
		{
			h+=U;
			if(h>H)
			{
				cout<<"success on day "<<day<<'\n';
				break;
			}
			h-=D;
			if(h<0)
			{
				cout<<"failure on day "<<day<<'\n';
				break;
			}
			U-=f;
			if(U<0)
			{
				U=0;
				f=0;
			}
			day++;
		}
		
	}
	return 0;
}

