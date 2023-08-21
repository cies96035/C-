#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 5e2 + 5;
int n;
int a[MAX_N];
void f(){
    cin >> n;
    rep(i, 0, n){
        cin >> a[i];
    }
    int Min = 1e9 + 5;
    int ans = 0;
    rvep(i, n - 1, 0){
        if(a[i] > Min){
            ans = max(ans, a[i]);
        }else{
            Min = min(Min, a[i]);
        }
    }
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