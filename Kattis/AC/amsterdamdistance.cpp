#include<iostream>
#include<cmath>
using namespace std;
using ld = long double;
int M, N;
int a, b, c, d;
ld R, r, arc;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> M >> N >> R;
    cin >> a >> b >> c >> d;

    r = R / N;
    arc = r * std::abs(a - c) * min(b, d) * M_PI / M;
    cout << r * std::abs(b - d) + arc << '\n';
    return 0;
}