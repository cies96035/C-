#include<iostream>
using namespace std;

//稍微優化,原程式碼0.56壓到0.02 

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n,A,F;
	string graph;
	cin>>n;
	while(n--)
	{ 
		cin>>A>>F;
		for(int i=1;i<A;i++)
		{
			for(int j=0;j<i;j++)
				graph+=(char)(i+'0');
			graph+=(char)('\n');
		}
		for(int i=A;i>0;i--)
		{
			for(int j=0;j<i;j++)
				graph+=(char)(i+'0');
			graph+=(char)('\n');
		}
			
		while(F--)
		{
			cout<<graph;
			if((n||F))cout<<endl; 
		} 
		graph="";
	}
	return 0;
}

