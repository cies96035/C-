#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, a, b) for(int i = a; i <= b; i++)

int n;
int k;
ld ans = 0;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> k;
    rep(i, 1, k){
        ans += ( pow(i, n) - pow(i - 1, n) ) * i;
    }
    cout << fixed << setprecision(6) << ans / pow(k, n) << '\n';
    return 0;
}