#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

bool check(ld a2, ll x, ll y){
    ll a1 = x - a2;
    return a1 * a2 <= y;
}
pll Find1(ll x, ll y){
    ll l = x / 2, r = 1e9 + 5, mid;
    while(l < r){
        mid = (l + r) >> 1;
        if(check(mid, x, y)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    if(l * (x - l) == y) return {l, x - l};
    return {0, 0};
}

void f(){
    int n;
    cin >> n;
    ll a;
    map<ll, ll> cnt;
    rep(i, 0, n){
        cin >> a;
        cnt[a]++;
    }
    int q;
    ll xx, yy;
    cin >> q;
    rep(i, 0, q){
        ll sum = 0;
        cin >> xx >> yy;
        pll tmp = Find1(xx, yy);
        ll xx = tmp.first, yy = tmp.second;
        if(xx == yy){
            if(cnt.count(xx)){
                sum += cnt[xx] * (cnt[xx] - 1) / 2;
            }
        }else if(cnt.count(xx) && cnt.count(yy)){
            sum += cnt[xx] * cnt[yy];
        }
        cout << sum << ' ';
    }
    cout << '\n';
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