#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)
// 9
// 5 7 6 2
// 8
void f(){
    int n, m, a;
    cin >> n;
    vector<pll> as;
    ll ans = 0;
    ll Min = 1e9;
    rep(i, 0, n){
        cin >> m;
        as.push_back({1e9 + 5, 1e9 + 5});
        rep(j, 0, m){
            cin >> a;
            if(a < as.back().second) as.back().second = a;
            if(as.back().second < as.back().first)
                swap(as.back().first, as.back().second);
        }
        Min = min(as.back().second, Min);
    }
    sort(as.begin(), as.end());
    ans = as[0].first;
    rep(i, 0, as.size()) ans += as[i].second;
    ans -= Min;
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