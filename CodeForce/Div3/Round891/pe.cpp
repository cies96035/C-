#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 5;
pll x[MAX_N];
ll ans[MAX_N];
void f(){
    int n;
    cin >> n;
    ll sum = 0;
    rep(i, 0, n){
        cin >> x[i].first;
        x[i].second = i;
        sum += x[i].first;
    }
    sort(x, x + n);
    sum -= (x[0].first - 1) * n;
    ans[x[0].second] = sum;
    rep(i, 1, n){
        ll d = x[i].first - x[i - 1].first;
        sum += (i - (n - i)) * d;
        ans[x[i].second] = sum;
    }
    rep(i, 0, n){
        cout << ans[i] << ' ';
    }
    cout << '\n';

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