#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
using ld = long double;

ld a, b, c, d, s;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> a >> b >> c >> d;
    s = a + b + c + d;
    s /= 2;
    cout << fixed << setprecision(10) << sqrt((s - a) * (s - b) * (s - c) * (s - d)) << '\n';
    return 0;
}