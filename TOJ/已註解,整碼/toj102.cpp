#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	cout<<fixed<<setprecision(4);
	//�D�بS���d��,����S�Ψ�long double�|WA 
    long double a,b;
    char x;
    cin>>a>>x>>b; 
    if(x=='+')
    cout<<a<<" + "<<b<<" = "<<a+b<<endl;
    else if(x=='-')
    cout<<a<<" - "<<b<<" = "<<a-b<<endl;
    else if(x=='*')
    cout<<a<<" * "<<b<<" = "<<a*b<<endl;
    else
    {
        if(b)cout<<a<<" / "<<b<<" = "<<a/b<<endl;
        else{cout<<"ERROR"<<endl;}
    }
    return 0;
}
