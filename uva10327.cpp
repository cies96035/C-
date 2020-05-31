#include<iostream>
using namespace std;

#define maxN 1010

int N,arr[maxN],cnt;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin>>N)
	{
		cnt=0;
		for(int i=0;i<N;i++)
			cin>>arr[i];
		for(int i=N-1;i>=0;i--)
			for(int j=i+1;j<N;j++)
				if(arr[j-1]>arr[j])
				{
					swap(arr[j-1],arr[j]);
					cnt++;
				}
		cout<<"Minimum exchange operations : "<<cnt<<'\n';
	}
	return 0;
}

