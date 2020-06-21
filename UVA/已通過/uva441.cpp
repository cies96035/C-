#include<iostream>
#include<algorithm> 
using namespace std;

//max length
#define Max 15

int arr[Max],n;
bool dontneedprint[Max],newline=0;
string output="     \n";//char after num

//print the needy num
void print()
{
	for(int i=0,j=0;j<6;i++)
		if(!dontneedprint[i])
			cout<<arr[i]<<output[j++];
	return;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin>>n&&n)
	{
		if(newline++)//need a newline between every tests
			cout<<'\n';
		
		//Init
		for(int i=0;i<6;i++)
			dontneedprint[i]=0;
		for(int i=6;i<n;i++)
			dontneedprint[i]=1;
		
		//Input
		for(int i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n);
		
		//00000011
		//->next_permutation->
		//00000101->00000110...
		do
		{
			print();
		}while(next_permutation(dontneedprint,dontneedprint+n));
	}
	return 0;
}

