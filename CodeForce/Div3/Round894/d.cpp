#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

void f(){
    ll n;
    cin >> n;
    ll l = 2, r = 1.5e9, mid;
    
    while(l < r){
        mid = (l + r) >> 1;
        if(mid * (mid - 1) / 2 + mid >= n){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    ll ans = l + n - l * (l - 1) / 2;
    l++;
    if(n >= l * (l - 1) / 2)
        ans = min(ans, l + n - l * (l - 1) / 2);
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

/*
1 : 2
2 : 3
3 : 3
4 : 4
5 : 4
6 : 4
C(n, 2) + k
n + k
*/