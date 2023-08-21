#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 5;
int a[MAX_N];
void f(){
    int n, k, q;
    cin >> n >> k >> q;
    int cnt = 0;
    ll ans = 0;
    rep(i, 0, n){
        cin >> a[i];
        if(a[i] <= q) cnt++;
        else cnt = 0;
        if(cnt >= k) ans += cnt - k + 1;
    }
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