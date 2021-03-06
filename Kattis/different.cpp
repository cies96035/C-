#include<iostream>
using namespace std;
using ull = unsigned long long;

ull a, b;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> a >> b){
        if(a > b){
            cout << a - b << '\n';
        }else{
            cout << b - a << '\n';
        }
    }
    return 0;
}