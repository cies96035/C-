#include<iostream>
using namespace std;

int ans[101];

int main()
{
	for(int i=1;i<=100;i++)
		ans[i]=ans[i-1]+i*i;
		
	int N;
	while(cin>>N)
	{
		if(N==0)return 0;
		cout<<ans[N]<<endl;
	}
	
}

