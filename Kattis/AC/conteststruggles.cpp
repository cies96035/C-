#include<bits/stdc++.h>
using namespace std;
using ld = long double;

int n, k;
int d, s;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> k >> d >> s;
    d *= n;
    d -= s * k;
    n -= k;
    if(d < 0 || d > 100 * n){
        cout << "impossible\n";
    }else{
        cout << fixed << setprecision(8) << (ld)d / n << '\n';
    }

    return 0;
}