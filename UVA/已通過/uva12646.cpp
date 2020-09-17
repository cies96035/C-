#include<iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    bool A,B,C;
    while(cin>>A>>B>>C)
    {
        if(A==B&&B==C)
            cout<<"*\n";
        else
            if(A==B)
                cout<<"C\n";
            else if(A==C)
                cout<<"B\n";
            else
                cout<<"A\n";
    }
    return 0;
}