#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 5;
pll a[MAX_N];
int b;
void f(){
    int n;
    cin >> n;
    rep(i, 0, n) cin >> a[i].first;
    rep(i, 0, n){
        cin >> b;
        a[i].first -= b;
        a[i].second = i;
    };
    sort(a, a + n);
    int MAX = a[n - 1].first;
    vector<int> ans;
    rvep(i, n - 1, 0){
        if(a[i].first != MAX) break;
        ans.push_back(a[i].second);
    }
    cout << ans.size() << '\n';
    rvep(i, ans.size() - 1, 0){
        cout << ans[i] + 1 << ' ';
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