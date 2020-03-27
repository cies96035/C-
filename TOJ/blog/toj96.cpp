#include<iostream>
using namespace std;

int main() {
    int a,b;
    char c;
    cin >>a>>c>>b;
    if(c=='+')
        cout<<a<<" + "<<b<<" = "<< a+b << endl;    
    else if(c=='-')
        cout<<a<<" - "<<b<<" = "<< a-b << endl;
    else if(c=='*')
        cout<<a<<" * "<<b<<" = "<< a*b << endl;
    else
    {
        if(!b)
            cout<<"ERROR"<<endl;
        else
			cout<<a<<" / "<<b<<" = "<< a/b<<" ... "<<a%b<< endl;
    }
    return 0;
}
