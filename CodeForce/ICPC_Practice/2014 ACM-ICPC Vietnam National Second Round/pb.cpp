#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define int ll
#define IOS ios::sync_with_stdio(0); cin.tie(0)
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    int ans = 0, i;
    int aed = 0, a = 0;
    int sn = sqrt(n);
    for (i = 1; n / i > i; ++i) 
    {
        ans += n / i + i * ((n / i) - (n / (i + 1)));
    }
    ans += i * ((n / i) - (n / (i + 1)));

    cout << ans << endl;
}

signed main () {
    int t;
    cin >> t;
    while (t--)
        solve();
}