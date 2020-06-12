#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

int t,n,num;
long double sum;
int value[70000];
char c;
string s;
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
		cin.ignore();
		while((n--)&&getline(cin,s))
		{
			for(int i=0;i<s.size();i++)
				sum+=value[s[i]];
		}
		
		cout<<fixed<<setprecision(2)<<sum/100<<"$\n";
		
	}
	return 0;
}

