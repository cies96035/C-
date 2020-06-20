#include<iostream>
using namespace std;

// max(borrow one bottle,borrow two bottle)
int borrow,N;
int cola(int coke,int Empty)
{
	int Sum=(coke+Empty);
	if(Sum<3)
	{
		if(borrow>coke)
			return -2e9;
		return coke;
	}
	else
		return cola(Sum/3,Sum%3)+coke;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin>>N)
		cout<<max(cola(N,borrow=1),cola(N,borrow=2))<<'\n';
	return 0;
}

