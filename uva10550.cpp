#include<iostream>
using namespace std;

//strange ans...

int a,b,c,d,ans;
int degree(int a,int b,bool r)
{
	if(a==b)
		return 360;
	if(!r)
	{
		if(a<b)
			return (b-a)*9;
		else
			return (b-a)*9+360;
	}
	else
	{
		if(a>b)
			return (a-b)*9;
		else
			return (a-b)*9+360;
	}
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin>>a>>b>>c>>d&&(a||b||c||d))
	{
		ans=0;
		ans+=degree(a,a,1)*2;
		ans+=degree(a,b,1);
		ans+=degree(b,b,0);
		ans+=degree(b,c,0);
		ans+=degree(c,d,1);
		cout<<ans<<'\n';
	}
	return 0;
}

