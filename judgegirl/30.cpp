#include<iostream>
using namespace std;
 
int arr[20][20],sum[20][20];
 
int main() {
	int r,c;
	cin>>r>>c;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			cin>>arr[i][j];
	sum[r][0]=arr[r][0]=1;
	for(int i=r;i>0;i--)
		for(int j=1;j<=c;j++)
		{
			if(arr[i+1][j])sum[i][j]+=sum[i+1][j];
			if(arr[i][j-1])sum[i][j]+=sum[i][j-1];
		}
	cout<<sum[1][c]<<endl;
	return 0;
}
 
