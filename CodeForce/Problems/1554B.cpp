#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i <= b; i++)

const int MAX_N = 1e5 + 5;
const int INF = 0x3fffffff;
int t, n, k;
ll a[MAX_N], ans;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    /*
    1 <= k <= 100
    0 <= ai|aj <= n
    i * j <= n * (n - 1)
    x * y - 0   <--->   i * j - k * n
    */
    cin >> t;
    while(t--){
        cin >> n >> k;
        rep(i, 1, n){
            cin >> a[i];
        }
        ans = -INF;
        for(ll j = n; j > 1 && ans < (j - 1) * j; j--){
            for(ll i = j - 1; i >= 1 && ans < i * j; i--){
                ans = max( ans, i * j - k * (a[i] | a[j]) );
            }
        }
        cout << ans << '\n';
    }
    return 0;
}