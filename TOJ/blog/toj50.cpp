#include<iostream>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	//�̷��D�حn�D���N�n...
	//!!�����������!! 
    int Key;
    char a1,a2,a3,a4,a5,a6,a7;
    cin>>Key;
    while(cin>>a1>>a2>>a3>>a4>>a5>>a6>>a7)
    {
        char ASCII=0;
        //���O�̷ӿ�J���r���P�_ASCII�j�p 
        if(a1=='X')ASCII+=64;
        if(a2=='X')ASCII+=32;
        if(a3=='X')ASCII+=16;
        if(a4=='X')ASCII+=8;
        if(a5=='X')ASCII+=4;
        if(a6=='X')ASCII+=2;
        if(a7=='X')ASCII+=1;
        //���D�حn�D ASCII Xor Key
        // ^�Oxor�B��Ÿ��A�Ϊk�p�P+-*/%... 
        ASCII^=Key;
        cout<<ASCII;
    }
    return 0;
}
