#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
using ld = long double;

ld p, a, b, c, d, n, pi;
ld sum = 0, maxPrice = 0, maxDecline = 0;
inline ld price(ld k){
    return p * ( sin(a * k + b) + cos(c * k + d) + 2 );
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> p >> a >> b >> c >> d >> n;
    for(int i = 1; i <= n; i++){
        pi = price(i);
        if(pi > maxPrice){
            maxPrice = pi;
        }
        if(maxPrice - pi > maxDecline){
            maxDecline = maxPrice - pi;
        }
    }
    cout << fixed << setprecision(8) << maxDecline << '\n';
    return 0;
}