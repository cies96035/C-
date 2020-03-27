#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	long long generation[81]={1,1},num;
	for(int i=2;i<=80;i++)
	{
		generation[i]=generation[i-1]+generation[i-2];
	}
	while(cin>>num)
	{
		if(!num)break;
		cout<<generation[num]<<endl;
	}
	return 0;
}

