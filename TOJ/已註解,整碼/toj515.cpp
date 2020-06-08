#include<iostream>
using namespace std;

int main()
{
	int N;
	cin>>N;
	
	if(N%1111==0 && N>=1000&&N < 10000)
		cout<<"GREAT!!\n";
	else
		cout<<"OAQ\n";
	return 0;
}
