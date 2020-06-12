#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

int t,n,num;
long double sum;
int value[256];
unsigned char c;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>t;
	while(t--)
	{
		sum=0;
		memset(value,0,sizeof(value));
		
		cin>>n;
		while(n--)
		{
			cin>>c>>num;
			value[c]=num;
		}
		
		cin>>n;
		while(c=cin.get())
		{
			if(c=='\n'&&!(n--))
				break;
			else
				sum+=value[c];
		}
		
		cout<<fixed<<setprecision(2)<<sum/100<<"$\n";
		
	}
	return 0;
}

