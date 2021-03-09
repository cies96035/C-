#include<iostream>
using namespace std;

int X, Y;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> X >> Y;
    if(Y & 1){
        cout << "impossible\n";
    }else{
        cout << "possible\n";
    }
    return 0;
}