#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	cout<<fixed<<setprecision(2);//���p���I�G�� 
    long double R1,I1,R2,I2;
    char Oper;
    cin>>R1>>I1>>Oper>>R2>>I2;
    if(Oper=='+')
    {
        cout<<R1+R2;//��� 
        if(I1-I2>=0)cout<<'+';//���Ʈɸ�+ 
        cout<<I1+I2<<'i'<<endl;//��� 
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
