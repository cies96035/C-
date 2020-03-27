#include<iostream>
using namespace std;

int main()
{
	int N;
	cin>>N;
	int A[N],arr[N],Max;
	for(int i=0;i<N;i++)
		cin>>A[i];
	for(int i=0;i<N;i++)
	{
		arr[i]=A[i];
		for(int j=0;j<i;j++)
		{
			for(int k=j+1;k<i;k++)
				arr[i]=max(arr[i],arr[j]-A[k]+A[i]);
		}
		Max=max(Max,arr[i]);
	}
	cout<<Max<<endl;
	return 0;
}/*
2 1 3 7 5
2 2 4 8 8
7 3 7 3 7
1 5 0

*/
