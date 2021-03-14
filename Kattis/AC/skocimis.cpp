#include<iostream>
using namespace std;

int A, B, C;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> A >> B >> C;
    if(B - A > C - B){
        cout << B - A - 1 << '\n';
    }else{
        cout << C - B - 1 << '\n';
    }
    return 0;
}