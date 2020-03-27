#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int t,salary[3];
	cin>>t;
	for(int Case=0;Case<t;)
	{
		cin>>salary[0]>>salary[1]>>salary[2];
		sort(salary,salary+3);
		cout<<"Case "<<++Case<<": "<<salary[1]<<'\n';
	}
	return 0;
}

