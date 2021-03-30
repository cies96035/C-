#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
using ld = long double;

const ld delta = 0.0000001;
ld t[4];
ld m;
ld sum1, sum2, sum3;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i = 0; i < 4; i++){
        cin >> t[i];
    }
    cin >> m;

    sort(t, t + 4);
    sum1 = sum2 = 0;
    for(int i = 0; i < 3; i++){
        sum1 += t[i];
        sum2 += t[i + 1];
    }
    if(sum1 > 3 * m){
        cout << "impossible\n";
    }else if(sum2 < 3 * m + delta){
        cout << "infinite\n";
    }else{
        sum3 = t[1] + t[2];
        cout << fixed << setprecision(2) << 3 * m - sum3 << '\n';
    }
    return 0;
}