#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;
using ld = long double;

ld r;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> r;
    cout << fixed << setprecision(10);
    cout << r * r * M_PI << '\n';
    cout << r * r * 2 << '\n';

    return 0;
}