#include<iostream>
#include<cstring>
using namespace std;

int arr[200],n=0,len[200];

bool ispal(int s,int e)
{
	while(s<e)
	{
		if(arr[s]!=arr[e])
			return false;
		s++;
		e--;
	} 
	return true;
} 
int main()
{
	char k;
	int sum=0;
	while(cin.get(k))
	{
		if(k>='0'&&k<='9')
			sum=sum*10+k-'0';
		else if(k==' ')
		{
			arr[n++]=sum;
			sum=0;
		}
		else
		{ 
			arr[n++]=sum;
			break;
		} 
	}
	for(int i=0;i<n;i++)
	{
		for(int j=n-1;j>=0;j--)
		{
			if(ispal(i,j))
			{
				len[i]=j-i+1;
				break;
			}
		}
		cout<<len[i]<<endl;
	}
	//for(int i=0;i)
	return 0;
}

