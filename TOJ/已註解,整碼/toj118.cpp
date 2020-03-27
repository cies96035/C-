#include<iostream>
using namespace std;

int main()
{
	int N,M;
	cin>>N;
	int cost[N+1];
	while(N--)
	{
		int num,dollar;
		cin>>num>>dollar;
		cost[num]=dollar*num;
	}
	cin>>M;
	while(M--)
	{
		int num,dollar;
		cin>>num>>dollar;
		if(cost[num]==dollar)
			cout<<"The shopkeeper is honest."<<endl;
		else
			cout<<dollar-cost[num]<<endl;
	}
	
	return 0;
}

