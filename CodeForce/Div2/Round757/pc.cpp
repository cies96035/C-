#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MOD = 1e9 + 7;
const int MAX_N = 2e5 + 10;
ll t;
ll n, m;
ll x[MAX_N];
struct A{
    ll l, r, x;
    bool operator <(A xx){
        if(l != xx.l){
            return l < xx.l;
        }else if(x != xx.x){
            return x < xx.x;
        }else{
            return r < xx.r;
        }
    }
}a[MAX_N];
ll qpow(ll b, ll n, ll m){ //base ^ n % M
    ll ans = 1;
    while(n){
        if(n & 1){
            ans *= b, ans %= m;
        }
        b *= b, b %= m;
        n >>= 1;
    }
    return ans;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n >> m;
        rep(i, 0, n){
            x[i] = 0;
        }
        rep(i, 0, m){
            cin >> a[i].l >> a[i].r >> a[i].x;
        }
        sort(a, a + m);
        ll sum = 0;
        ll cnt[32] = {0};
        rep(i, 0, m){
            rep(j, 0, 32){
                if((a[i].x >> j) & 1){
                    cnt[j]++;
                }
            }
        }
        // rep(i, 0, 32){
        //     cout << cnt[i] << ' ';
        // }
        // cout << endl;
        rep(i, 0, 32){
            if(cnt[i])
                sum += qpow(2, n - 1 + i, MOD);
                sum %= MOD;
        }
        cout << sum << '\n';
    }
    return 0;
}