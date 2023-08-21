#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

int n;
const int MAX_N = 2e5 + 5;
int a[MAX_N];
bool check(ll v){
    ll x[3], xIdx = 0;
    x[0] = a[0] + v;
    rep(i, 1, n){
        if(a[i] - x[xIdx] > v){
            if(xIdx == 2) return false;
            x[++xIdx] = a[i] + v;
        }
    }
    return true;
}
void f(){
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    sort(a, a + n);
    int l = 0, r = 1e9, mid;
    while(l < r){
        mid = (l + r) >> 1;
        if(check(mid)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    cout << l << '\n';
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