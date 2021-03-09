#include<iostream>
using namespace std;

string Y, P;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> Y >> P;
    if(Y.back() == 'e'){
        Y += 'x';
    }else if(Y.back() == 'a' || Y.back() == 'i' || Y.back() == 'o' || Y.back() == 'u'){
        Y.back() = 'e';
        Y += 'x';
    }else if(Y.substr(Y.size() - 2, 2) != "ex"){
        Y += "ex";
    }
    cout << Y << P << '\n';
    return 0;
}