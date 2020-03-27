#include<iostream>
#include<algorithm> 
using namespace std;

int main()
{
	float a[2]={0.3,0.2};
	sort(a,a+2);
	cout<<a[0]<<a[1]<<endl;
	return 0;
}

