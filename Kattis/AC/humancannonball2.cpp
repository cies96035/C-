#include<iostream>
#include<cmath>
using namespace std;
using ld = long double;

int T;
ld v, theta, x, h1, h2;
ld t, y;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    while(T--){
        cin >> v >> theta >> x >> h1 >> h2;
        theta *= M_PI / 180;
        t = x / cos(theta) / v;
        y = v * t * sin(theta) - t * t * 9.81 / 2;
        if(h1 + 1 < y && y < h2 - 1){
            cout << "Safe\n";
        }else{
            cout << "Not Safe\n";
        }
    }
    return 0;
}