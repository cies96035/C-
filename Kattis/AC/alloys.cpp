#include<iostream>
using namespace std;
using ld = long double;
ld c;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> c;
    if(c > 1){
        cout << 0.25 << '\n';
    }else{
        cout << (c / 2) * (c / 2) << '\n';
    }
    return 0;
}