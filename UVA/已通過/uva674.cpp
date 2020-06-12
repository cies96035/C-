#include<iostream>
using namespace std;

#define Max 10000
int coin[5]={1,5,10,25,50};
int n;
int method[Max];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	/*
	method[0]=1;
	for(int i=0;i<5;i++)
		for(int j=0;j<Max;j++)
			method[j+coin[i]]+=method[j];
	*/	
	method[0]=1;
	for(int i=0;i<5;i++)
		for(int j=coin[i];j<Max;j++)
			method[j]+=method[j-coin[i]];
	/*
	method[x+coin]=method[x+coin]+method[x];
	method[26]=method[1]+method[16]+method[21]+method[25]
	if coin[i]==1
	11111 11111 11111 11111 11111 11111
	+ coin[i]=5
	11111 22222 33333 44444 55555 66666
	+ coin[i]=10
	11111 22222 44444 66666 99999 1212121212
	25
	11111 22222 44444 66666 99999 1313131313
	50
	11111 ....
	
	*/
	while(cin>>n)
		cout<<method[n]<<'\n'; 
	return 0;
}

