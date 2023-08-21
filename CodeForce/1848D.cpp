#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

ll n, k;
ll cal(ll tr){
    if(tr < 0 || tr >= k) return 0;
    ll ans = n, tmp = k - tr;
    if(tr){
        tr--;
        ans += ans % 10;
    } 
    ans += (tr / 4) * 20;
    tr %= 4;
    while(tr){
        tr--;
        ans += ans % 10;
    }
    return ans * tmp;

}
void f(){
    cin >> n >> k;
    ll ans = 0;
    if(n % 5){ 
        ll center = (k * 5 - n) / 10;
        rep(i, 0, 5) 
            ans = max(ans, cal(i));
        rep(i, max(0ll, center - 10), min(k, center + 10))
            ans = max(ans, cal(i));
    }else{
        ans = max(n * k, (n + n % 10) * (k - 1));
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