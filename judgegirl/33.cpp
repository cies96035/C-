#include<iostream>
using namespace std;

int arr[200][200];
const int m[4][2]={{-1,0},{0,-1},{1,0},{0,1}};

bool isintersection(int a,int b)
{
	for(int i=0;i<4;i++)
		if(!arr[a+m[i][0]][b+m[i][1]])
			return false;
	return true;
}
bool isTjunction(int a,int b)
{
	int z=0;
	for(int i=0;i<4;i++)
	{
		if(!arr[a+m[i][0]][b+m[i][1]])
			z++;
		if(z>1)
			return false;
	}
	return true;
}
bool isturn(int a,int b)
{
	int z=0;
	for(int i=0;i<4;i++)
	{
		if(!arr[a+m[i][0]][b+m[i][1]])
			z++;
		if(z>2)
			return false;
	}
	if(arr[a+1][b]==arr[a-1][b])
		return false;
	return true;
}
bool isdead_end(int a,int b)
{
	int one=0;
	for(int i=0;i<4;i++)
	{
		if(arr[a+m[i][0]][b+m[i][1]])
			one++;
		if(one>1)
			return false;
	}
	return true;
}
int main()
{
	int n,ans[4]={0};
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>arr[i][j];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(arr[i][j]==1)
			{
				if(isintersection(i,j))
					ans[0]++;
				else if(isTjunction(i,j))
					ans[1]++;
				else if(isturn(i,j))
					ans[2]++;
				else if(isdead_end(i,j))
					ans[3]++;
			}
		}
	}
	cout<<ans[0]<<endl<<ans[1]<<endl<<ans[2]<<endl<<ans[3]<<endl;
	return 0;
}

