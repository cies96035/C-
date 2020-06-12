#include<iostream>
using namespace std;

typedef long long ll;

ll limit,step,A,Case=1;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin>>A>>limit&&A>0)
	{
		cout<<"Case "<<Case++<<": A = "<<A<<", limit = "<<limit<<", number of terms = ";
		step=0;
		while(A!=1&&A<=limit)
		{
			if(A%2)
				A=3*A+1;
			else
				A/=2;
			step++; 
		}
		if(A==1)
			step++;
		cout<<step<<'\n';
	}
	return 0;
}

