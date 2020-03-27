#include<iostream>
#include<string.h>
using namespace std;

int main() {
    string A,B;
    int a,b;
    cin>>A>>a>>B>>b;
    if(A==B)
    {
        if(a==b)
            cout<<"GOOD"<<endl;
        else
            cout<<"=~="<<endl;
    }
    else
    {
        if(a==b)
            cout<<"=~="<<endl;
        else
            cout<<"OTZ"<<endl;
    }
}
