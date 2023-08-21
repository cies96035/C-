#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 3e5 + 5;
pll a[MAX_N];
void f(){
    int n, k;
    cin >> n >> k;
    rep(i, 0, n){
        cin >> a[i].first;
        a[i].first += k - 1;
        a[i].first %= k;
        a[i].first = - a[i].first;
        a[i].second = i + 1;
    }
    sort(a, a + n);
    rep(i, 0, n){
        cout << a[i].second << ' ';
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