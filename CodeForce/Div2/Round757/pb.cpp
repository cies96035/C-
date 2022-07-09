#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 5;
int t;
int n;
pll a[MAX_N];
ll ans[MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        rep(i, 0, n){
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a, a + n);
        int cnt = 1;
        for(int i = n - 1; i >= 0; i--){
            ans[a[i].second + 1] = cnt;
            if(cnt > 0) cnt = -cnt;
            else cnt = -cnt + 1;
        }
        ll sum = 0;
        rep(i, 0, n){
            // cout << ans[a[i].second + 1] << ' ' << a[i].first << endl;
            sum += abs(ans[a[i].second + 1] * a[i].first);
        }
        cout << 2 * sum << '\n';
        rep(i, 0, n + 1){
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}