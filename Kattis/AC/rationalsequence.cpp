#include<iostream>
using namespace std;
using ull = unsigned long long;

ull P;
ull K, a, b;
char c;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> P;
    while(P--){
        cin >> K >> a >> c >> b;
        if(b == 1){ // Case 1
            cout << K << ' ' << b << '/' << a + 1 << '\n';
        }else if(a > b){ // Case 2 
            cout << K << ' ' << b << '/' << b * (a / b + 1) - a % b << '\n';
        }else if(a < b){ // Case 3
            cout << K << ' ' << b << '/' << b - a << '\n';
        }
    }
    
    return 0;
}