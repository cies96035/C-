#include<iostream>
#include<iomanip>
using namespace std;
using ld = long double;

ld C, L;
ld w, l;
ld sum;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> C >> L;
    for(int i = 0; i < L; i++){
        cin >> w >> l;
        sum += w * l;
    }
    cout << fixed << setprecision(8) << sum * C << '\n';
    return 0;
}