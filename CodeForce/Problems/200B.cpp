#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, a, b) for(int i = a; i < b; i++)

int n, ipt;
ld sum;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    rep(i, 0, n){
        cin >> ipt;
        sum += ipt;
    }
    cout << fixed << setprecision(10) << sum / n << '\n';
    return 0;
}