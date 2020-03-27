#include<iostream>
using namespace std;

int main()
{
    string A,B;
    while(cin>>A>>B)
    {
        if(A[0]!='-'&&A==B)
            cout<<"Nymphia"<<endl;
        else
             cout<<"Fake"<<endl;
    }
    return 0;
}
