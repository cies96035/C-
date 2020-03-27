#include<iostream>
using namespace std;

int main()
{
	int N;

	cin>>N;
	//gray code
	for (unsigned int i = 0; i < (1 << N); i++)
    	cout << (i ^ (i >> 1))<<' ';
	return 0;
}

