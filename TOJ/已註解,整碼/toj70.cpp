#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	cout<<fixed<<setprecision(2);//计翴 
    long double R1,I1,R2,I2;
    char Oper;
    cin>>R1>>I1>>Oper>>R2>>I2;
    if(Oper=='+')
    {
        cout<<R1+R2;//龟计 
        if(I1-I2>=0)cout<<'+';//タ计干+ 
        cout<<I1+I2<<'i'<<endl;//店计 
	} 
    else if(Oper=='-')
    {
        cout<<R1-R2;
        if(I1-I2>=0)cout<<'+';
        cout<<I1-I2<<'i'<<endl;
	}
    else if(Oper=='*')
    {
        cout<<R1*R2-I1*I2;
        if(I1*R2+R1*I2>=0)cout<<'+';
        cout<<I1*R2+R1*I2<<'i'<<endl;
    }
    else if(Oper=='/')
    {
        cout<<(R1*R2+I1*I2)/(R2*R2+I2*I2);
        if((I1*R2-R1*I2)/(R2*R2+I2*I2)>=0)cout<<'+';
        cout<<(I1*R2-R1*I2)/(R2*R2+I2*I2)<<'i'<<endl;
    }
    return 0;
}
