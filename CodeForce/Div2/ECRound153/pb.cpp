#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

int m, k, a, b;
void f(){
    cin >> m >> k >> a >> b;
    int ans = 0;
    if(a >= k){
        b += a / k - 1;
        a -= (a / k - 1) * k;
    }
    // cout << a <<' ' << b << endl;
    ans = max(0, ((m / k) - b)) + max(0, ((m % k) - a));
    b += a / k;
    a %= k;
    // cout << a <<' ' << b << endl;
    ans = min(ans, max(0, ((m / k) - b)) + max(0, ((m % k) - a)));
    cout << ans << '\n';
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while(t--) f();
    
    return 0;
}