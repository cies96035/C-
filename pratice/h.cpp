#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)//輸出共n層 
	{ 
		for(int j=0;j<i;j++)//每層輸出i次
			cout<<i;//每層輸出i 
		cout<<endl;
	} 
	return 0;
}

