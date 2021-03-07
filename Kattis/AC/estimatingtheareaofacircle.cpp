#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
using ld = long double;

ld r, m, c;
ld area;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cout << fixed << setprecision(6);
    while(cin >> r >> m >> c && r && m && c){
        area = M_PI * r * r;
        cout << area << ' ' << 4 * c / m * r * r << '\n';
    }

    return 0;
}