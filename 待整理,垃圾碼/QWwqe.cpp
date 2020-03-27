#include<iostream>
using namespace std;

int main()
{
	int i[11]={0,0,0,0,0,0,0,0,0,0,0},ans=0;
	for(;i[0]<3;i[0]++)
	{
	for(;i[1]<3;i[1]++)
	{
	for(;i[2]<3;i[2]++)
	{
	for(;i[3]<3;i[3]++)
	{
	for(;i[4]<3;i[4]++)
	{
	for(;i[5]<3;i[5]++)
	{
	for(;i[6]<3;i[6]++)
	{
	for(;i[7]<3;i[7]++)
	{
	for(;i[8]<3;i[8]++)
	{
	for(;i[9]<3;i[9]++)
	{
	for(;i[10]<3;i[10]++)
	{
		int b=0;
		for(int j=0;j<=10;j++)
		{
			if(i[j]==2)b++;
			
		}
		for(int k=0;k<=8;k++)
		if(i[k]==i[k+1]&&i[k]==i[k+2]&&i[k]==1)b=2;
		if(b<=1)ans++;
		}
	i[10]=0;
	}
	i[9]=0;
	}
	i[8]=0;
	}
	i[7]=0;
	}
	i[6]=0;
	}
	i[5]=0;
	}	
	i[4]=0;
	}
	i[3]=0;
	}
	i[2]=0;
	}	
	i[1]=0;
	}
	cout<<ans<<endl;
	return 0;
}

