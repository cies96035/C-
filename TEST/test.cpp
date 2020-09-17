#include<iostream>
#include<fstream>
#include<queue>
using namespace std;
class A{
    public:A(){a=1;cout<<"AX"<<endl;}
    A(int x){a=x;cout<<"AX(int)"<<endl;
        if(x<0)throw(x);
    }
    ~A(){cout<<"DA:"<<a<<endl;}
    int a;
};
class B:public A{
    public:
    int b;
    B(): A(11){b=3;cout<<"CB"<<endl;}
    B(int y):A(y){b=y;cout<<"CB(int)"<<endl;}
    ~B(){cout<<"DB:"<<a<<"\t"<<b<<endl;}
};
class C:public A{
    public:
    C(){c=5;cout<<"CC"<<endl;}
    C(int z){c=z;cout<<"CC(int)"<<endl;}
    ~C(){cout<<"DC:"<<a<<"\t"<<c<<endl;}
    int c;
};
void foo(int &n)
{
    A a;
    B b1;
    B b2(n++);
    C *c =new C(++n);
    A* pa;
    pa=c;
    B* pb=static_cast<B*>(pa);
    cout<<pb<<endl;
    cout<<(*pb).b<<endl;
}
int main( ) {  
    int n=8;
    try{
        foo(n);
    }catch(int p)
    {
        cout<<'c'<<p<<endl;
    }
    return 0;
} 