#include<iostream>
using namespace std;
using ull = unsigned long long;

ull k;
ull a, b;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    a = 0, b = 1;
    cin >> k;
    for(int i = 1; i < k; i++){
        if(i & 1){
            a += b;
        }else{
            b += a;
        }
    }
    if(k & 1){
        cout << a << ' ' << b << '\n';
    }else{
        cout << b << ' ' << a << '\n';
    }
    return 0;
}