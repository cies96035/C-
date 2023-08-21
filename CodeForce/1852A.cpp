#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const ll MAX_N = 2e5 + 5;
int n, k;
ll arr[MAX_N];
bool check(ll idx, ll mid, ll d){
    return mid - idx >= d;
}
ll OneDay(ll d){
    ll l = 1, r = MAX_N * MAX_N, mid;
    while(l < r){
        mid = (l + r) >> 1;
        ll idx = lower_bound(arr, arr + n, mid) - arr;
        if(check(idx, mid, d + 1)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    return l - 1;
}
void f(){
    cin >> n >> k;
    rep(i, 0, n){
        cin >> arr[i];
    }
    ll ans = 1;
    rep(i, 0, k){
        ans = OneDay(ans);
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