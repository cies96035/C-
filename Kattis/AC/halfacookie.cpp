#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
using ld = long double;

ld r, x, y;
ld R, len, area;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cout << fixed << setprecision(6);
    while(cin >> r >> x >> y){
        R = sqrt(x * x + y * y);
        if(r < R){
            cout << "miss\n";
        }else{
            len = sqrt(r * r - R * R);
            area = acos(R / r) * r * r - len * R;
            cout << (r * r * M_PI) - area << ' ' << area << '\n';
        }
    }
    return 0;
}