#include<iostream>
using namespace std;
int pow2(int a,int b){
    int r=1,base=a;
    while(b!=0){
    if(b%2) r*=base;
    base*=base;
    b/=2;
    }
    return r;
}
int main()
{
	cout<<pow2(2,11)<<endl;
	return 0;
}

