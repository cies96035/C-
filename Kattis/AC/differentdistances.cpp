#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;
using ld = long double;

ld X1, X2, Y1, Y2, P;
ld norm(ld x, ld y, ld p){
    return pow( (pow(x, p) + pow(y, p)), 1 / p );
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cout << fixed << setprecision(10);
    while(cin >> X1){
        if(-0.00001 < X1 && X1 < 0.00001){
            break;
        }
        cin >> Y1 >> X2 >> Y2 >> P;
        cout << norm(ld( std::abs(X1 - X2) ), ld( std::abs(Y1 - Y2) ), P) << '\n';
    }

    return 0;
}