#include<iostream>
#include<algorithm>
using namespace std;

/*
example
1. (1+2)+(1+2+3)
2. (1+3)+(1+3+2)
3. (2+3)+(2+3+1)
*/ 

/*1 1 1 1
1
2
3
4
1234
12 3
33 6
64 10
105 15

12 3
33 9
94 22

*/
#define MaxN 5500
int arr[MaxN],DP[MaxN],sum,N;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin>>N&&N)
	{
		sum=0;
		for(int i=0;i<N;i++)
			cin>>arr[i];
			
		sort(arr,arr+N);
		
		DP[0]=arr[0];
		DP[1]=DP[0]+arr[1];
		for(int i=2;i<N;i++)
		{
			DP[i]=min((DP[i-2]+arr[i]+arr[i-1])*2,DP[i-1]*2+arr[i]);
			cout<<DP[i]<<endl;
		}
		cout<<DP[N-1]<<'\n';
	}
	return 0;
}

