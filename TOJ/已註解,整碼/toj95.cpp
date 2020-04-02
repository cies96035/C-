#include<iostream>
using namespace std;

int main()
{
	//依題目需求判斷... 
	int a,b;
	cin>>a>>b;
	if(a==1&&b>=8||a==2&&b>=9||a==3&&b>=10)
		cout<<"PASS!"<<endl;
	else 
		cout<<"FAIL! You see see you!"<<endl;
	return 0;
} 
