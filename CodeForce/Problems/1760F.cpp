#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 5;
ll t, n, c, d, a[MAX_N];

bool check(int k){
    ll sum = 0;
    int p = 0;
    rep(i, 0, d){
        if(p < n)
            sum += a[p];
        p++;
        if(p > k){
            p = 0;
        }
    }
    // cout << k << ' ' << sum << '\n';
    return sum >= c;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n >> c >> d;
        rep(i, 0, n){
            cin >> a[i];
        }
        sort(a, a + n, greater<int>());
        if(check(d + 1)){
            cout << "Infinity\n";
        }else if(!check(0)){
            cout << "Impossible\n";
        }else{
            int l = -2, r = d + 10, mid;
            while(l < r){
                mid = (l + r) / 2;
                if(check(mid)){
                    l = mid + 1;
                }else{
                    r = mid;
                }
            }
            cout << l - 1 << '\n';
        }
    }
    return 0;
}