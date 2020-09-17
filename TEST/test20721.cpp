#include <iostream>
using namespace std;

int main()
{
    char c[]={'a','b',0};
    int a[]={0x64636261,0x68676665,0x6C6B6A69,0};
    cout<<a<<endl;
    cout<<((char*)a+2)<<endl;
    cout<<(int*)((char*)a+2)<<endl;
    cout<<c<<endl;
    cout<<(int*)c<<endl;
    cout<<((bool*)a+2)<<endl;
    /*
    int *p=a;
    cout<<a<<endl;
    cout<<p<<endl;
    cout<<((char*)a)<<endl;*/
    return 0;
}