#include<iostream>
#include<cmath>
using namespace std;
using ld = long double;

ld a, b;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> a >> b;

    b = pow(2, b);
    if(a - 0.01 > b){
        cout << "You will become a flying monkey!\n";
    }else{
        cout << "Your wish is granted!\n";
    }
    return 0;
}