#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n[]={1,1,1,1,4,6,6};
	cout<<upper_bound(n,n+7,5)-n;
	return 0;
}

