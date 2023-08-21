#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 10;
ll n, c;
ll s[MAX_N];
void f(){
    ll t = 0;
    cin >> n >> c;
    rep(i, 0, n){
        cin >> s[i];
        c -= s[i] * s[i];
        t += s[i];
    }
    c /= 4;
    // cout << c << endl;
    unsigned long long l = 0, r = sqrt(1e18 / n) + 5, w;
    while(l < r){
        w = (l + r) >> 1;
        if(w * t + w * w * n >= c){
            r = w;
        }else{
            l = w + 1;
        }
    }
    cout << l << '\n';
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        f();
    }
    return 0;
}

// c = sum 4*(w * (s+w)) + s^2
// c = sum 4sw + 4w^2 + s^2
// 0 = 4nw^2 + tw - c + s^2