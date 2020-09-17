#include <iostream>
using namespace std;

class X{
    public:X(){a=0;}
    int a;
};
class Y:protected X{
    public: Y(){a=1;}
    int a;
};
class Z:public Y{
    public:Z(){a=2;}
};
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    X p;Y q;Z r;
    cout<<p.a<<endl;
    //cout<<q.X::a<<endl;
    cout<<(&r)->a<<endl;
    cout<<(&r)->Y::a<<endl;
    cout<<(*(&r)).a<<endl;
    return 0;
}