#include<iostream>
using namespace std;

int main() {
	//或是你要直接輸出left也是可以... 
	int num=2,count=1;
	while(num%71)
	{
		if(count%2)num*=2;
		else num++;
		count++;
	}
	if(!num%3)cout<<"right"<<endl;
	else cout<<"left"<<endl;
    return 0;
}
