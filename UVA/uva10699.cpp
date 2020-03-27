#include<iostream>
using namespace std;

const int maxX=1000001;

int prime[1000001]={0,0},num;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	//½è¼Æªí
	for(int i=2;i<maxX;i++)
		if(!prime[i])
			for(int j=i;j<maxX;j+=i)
				prime[j]++;
				
	while(cin>>num)
	{
		if(!num)return 0;
		cout<<num<<" : "<<prime[num]<<'\n';
	}
	return 0;
}

