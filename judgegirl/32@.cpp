#include<iostream>
#include<cstring>
using namespace std;

typedef pair<int,int> pii;
int arr[200],n=0,longest=0;
pii maxlen[200];
int best[2];

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
	
	//input part
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
	
	
	for(int i=n-1;i>=0;i--)
	{
		for(int j=n-1;j>=i;j--)
		{
			if(ispal(i,j))
			{
				maxlen[i]=pii(j-i+1,i);
				break;
			}
		}
		if(i>0&&maxlen[i+1].first>=maxlen[i].first)maxlen[i]=maxlen[i+1];
		//cout<<maxlen[i].first<<maxlen[i].second<<endl;
	}
	
	for(int i=n-1;i>=0;i--)
	{
		int l=0;
		//find i+1 head & longest second pal
		for(int k=i-1,j=k;j>=0;j--)
		{
			if(ispal(j,k))
			{
				if(k-j+1>=l)
				{
					l=k-j+1;
				}
			}
		}
		cout<<l<<maxlen[i].first<<endl;
		if(l+maxlen[i].first>longest)
		{
			longest=l+maxlen[i].first;
			best[0]=i;
			best[1]=l;
		}
	}
	cout<<best[0]<<best[1]<<endl;
	for(int i=best[0]-best[1];i<best[0];i++)
	{
		cout<<arr[i]<<' ';
	}
	for(int i=1;i<=best[1];i++)
	{
		cout<<arr[maxlen[best[1]].second+i]<<' ';
	}
	cout<<endl;
	
	return 0;
}
// 1 2 3 2 1 2 1

