#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 10;
void f(){
    int n;
    ll x, y;
    cin >> n;
    map<ll, int> xcnt, ycnt;
    map<ll, int> xycnt, yxcnt;
    ll cnt = 0;
    rep(i, 0, n){
        cin >> x >> y;
        cnt += xcnt[x]++;
        cnt += ycnt[y]++;
        cnt += xycnt[x + y]++;
        cnt += yxcnt[x - y]++;
    }
    cout << cnt * 2 << '\n';
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