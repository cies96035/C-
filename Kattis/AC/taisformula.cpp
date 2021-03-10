#include<iostream>
#include<iomanip>
using namespace std;
using ld = long double;

int N;
ld lt, lv, t, v;
ld sum;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    cin >> lt >> lv;
    while(--N){
        cin >> t >> v;
        sum += (t - lt) * (v + lv) / 2;
        lt = t;
        lv = v;
    }
    cout << fixed << setprecision(8);
    cout << sum / 1000 << '\n';
    return 0;
}