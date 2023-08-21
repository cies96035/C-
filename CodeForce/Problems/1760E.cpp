#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 5;
int a[MAX_N], p[MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t;
    int n;
    ll s;
    cin >> t;
    while(t--){
        cin >> n;
        s = 0;
        rrep(i, 1, n){
            cin >> a[i];
            p[i] = p[i - 1] + a[i];
            if(!a[i]){
                s += p[i - 1];
            }
        }
        ll ans = s;
        // cout << s << endl;
        rrep(i, 1, n){
            if(a[i] == 1){
                ans = max(ans, s + p[i - 1] - (n - i - (p[n] - p[i])));
            }else{
                ans = max(ans, s - p[i - 1] + (n - i - (p[n] - p[i])));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}