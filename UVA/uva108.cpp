#include<iostream>
using namespace std;

#define MaxN 105
//the maximum N is very small, so can just force
int arr[MaxN][MaxN];
int Max=-10000,num,N;
int main()
{
	cin>>N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin>>arr[i][j];
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			num=0;
			for(int k=i;k<N;k++)
				for(int l=j;l<N;l++)
				{
					num+=arr[k][j];
					if(num>Max)
						Max=num;
				}
		}
	cout<<Max<<endl;
	return 0;
}
