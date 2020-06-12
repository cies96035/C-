#include<iostream>
using namespace std;

string a,b;
int Min;

bool iscut(int x)
{
	if(x<0)
	{
		x=-x;
		for(int i=0;x<a.size();x++,i++)
			if(a[x]+b[i]-'0'>'3')
				return false;
	}
	else
		for(int i=0;i<a.size()&&x<b.size();i++,x++)
			if(a[i]+b[x]-'0'>'3')
				return false;
	return true;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin>>a>>b)
	{
		Min=1e9;
		if(a.size()>b.size())
			swap(a,b);
		
		for(int i=0;i<=b.size();i++)
		{
			if(iscut(i))
			{
				Min=max(a.size()+i,b.size());
				break;
			}
		}
		for(int i=1;i<a.size();i++)
		{
			if(iscut(-i))
			{
				if(Min>b.size()+i)
					Min=b.size()+i;
				break;
			}
		}
		cout<<Min<<'\n';
	} 
	return 0;
}

