#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int N;
	cin>>N;
	
	if(N%1111==0 && N>=1000&&N < 10000)
		cout<<"GREAT!!\n";
	else
		cout<<"OAQ\n";
	return 0;
}

