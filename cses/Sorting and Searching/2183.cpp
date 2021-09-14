#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 5;
ll n, x[MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    rep(i, 0, n){
        cin >> x[i];
    }
    sort(x, x + n);

    ll good = 1, idx = 0;
    while(idx < n && good >= x[idx]){
        good += x[idx];
        idx++;
    }
    cout << good << '\n';
    return 0;
}