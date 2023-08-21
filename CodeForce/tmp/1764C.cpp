#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 5;
int t, n, a[MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        rep(i, 0, n){
            cin >> a[i];
        }
        sort(a, a + n);
        if(a[0] == a[n - 1]){ // special case
            cout << n / 2 << '\n';
        }else{
            for(ll i = n / 2; i < n; i++){
                if(a[i] != a[n - i - 1]){
                    cout << i * (n - i) << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}