#include<iostream>
#include<cmath>
using namespace std;
using ld = long double;

ld h, v;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> h >> v;
    cout << ceil(h / sin(v / 180 * M_PI)) << '\n';

    return 0;
}