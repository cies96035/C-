#include<iostream>
#include<cstring>
using namespace std;

string ipt;
const int cs=210;
int ipts;
int c[cs];

string re(string n)
{
	string m=n;
	for(int i=0,j=ipts-1;i<ipts;i++,j--)
		m[j]=ipt[i]-'0';
	return m;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>ipt>>ipt;
	ipts=ipt.size();
	ipt=re(ipt);
	
	for(int i=0;i<ipts;i++)
		c[i]+=ipt[i]*(ipt[0]-1)*2;
	for(int i=1;i<ipts;i++)
		for(int j=0;j<ipts;j++)
			c[i+j]+=ipt[i]*(ipt[j])*2;
	for(int i=0;i<cs;i++)
	{
		if(c[i]>9)
		{
			c[i+1]+=c[i]/10;
			c[i]%=10;
		}
		if(c[i]<0)
		{
			int n=c[i]/10-1;
			c[i+1]+=n;
			c[i]-=10*n;
		}
	}
	
	for(int fg=1,i=cs-1;i>=0;i--)
	{
		if(fg&&c[i]==0)continue;
		cout<<c[i];
		fg=0;
	}
	
	cout<<endl;
	return 0;
}

