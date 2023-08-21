#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 1e3 + 5;
ll a[MAX_N];
ll preSum[MAX_N];
ll n, k;
ll intervalSum(int l, int r){
    return preSum[r + 1] - preSum[l];
}
bool test(int x, ll val){
    ll leftK = k;
    while(x != n - 1){
        leftK -= val - a[x];
        x++;
        val--;
        if(leftK < 0) return true;
        if(a[x] >= val){
            return false;
        }
    }
    return true;
}
void f(){
    cin >> n >> k;
    ll ans = 0;
    rep(i, 0, n){
        cin >> a[i];
        preSum[i + 1] = preSum[i] + a[i];
        ans = max(ans, a[i]);
    }
    rep(i, 0, n){
        ll l = a[i], r = 1e9, mid;
        while(l < r){
            mid = (l + r) >> 1;
            if(test(i, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }

        }
        ans = max(ans, l - 1);
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