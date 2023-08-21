#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)


int a[60];
void f(){
    int n;
    cin >> n;
    rep(i, 0, n){
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 0;
    for(int i = 0, j = n - 1; i < j; i++, j--){
        ans += a[j] - a[i];
    }
    cout << ans << '\n';
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