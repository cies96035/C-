#include<iostream>
#include<cmath>
using namespace std;
using ull = unsigned long long;
using ld = long double;

ld X;
ull n;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> X;
    n = round(X * 1000);
    n *= 5280;
    if(n % 4854 >= 2427){
        cout << n / 4854 + 1 << '\n';
    }else{
        cout << n / 4854 << '\n';
    }
    return 0;
}