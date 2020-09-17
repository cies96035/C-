#include <iostream>
using namespace std;
class A{
    public :
    A(){x=2;}
    virtual int c(){x=x++ +3;return x;}
    void p(){cout<<"PA:"<<x<<endl;}
    int x;
};
class B:public A{
    public:
    int c(){x=A::c()+5;return --x;}
    virtual void p(){cout<<"pB:"<<x<<endl;}
};
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    A x;B y;A *z;
    cout<<x.c()<<endl;
    cout<<y.c()<<endl;
    z=dynamic_cast<A*>(&y);
    x.x=z->c()+x.c();
    cout<<x.x<<endl;
    z=&x;
    z->x=z->c()+y.c();
    z->p();
    y.p();
    (static_cast<A*>(new B))->p();

    return 0;
}