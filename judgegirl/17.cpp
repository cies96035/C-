#include<iostream>
using namespace std;

int main()
{
	int r,c,ipt;
	cin>>r>>c;
	int arr[c]={0};
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		{
			cin>>ipt;
			arr[j]+=ipt;
		}
	for(int i=0;i<c;i++)
		cout<<arr[i]/r<<endl;
	return 0;
}

