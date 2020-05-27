#include<iostream>
using namespace std;

#define maxN 10100
int arr[maxN],index=0,num;
void insert_and_sort(int a)
{
	arr[index++]=a;
	for(int i=index-1;i>0;i--)
	{
		if(arr[i]<arr[i-1])
			swap(arr[i],arr[i-1]);
		else
			return;
	}
	return;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin>>num)
	{
		insert_and_sort(num);
		if(index%2)
			cout<<arr[index/2]<<'\n';
		else
			cout<<(arr[index/2]+arr[index/2-1])/2<<'\n';
	}
	return 0;
}

