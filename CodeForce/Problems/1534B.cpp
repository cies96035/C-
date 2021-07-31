#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i <= b; i++)

const int MAX_N = 400005;
int t, n;
ll a[MAX_N];
ll ans;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--)
    {
        ans = 0;
        cin >> n;
        rep(i, 1, n){
            cin >> a[i];
        }
        a[n + 1] = 0;
        rep(i, 0, n){
            ans += abs(a[i] - a[i + 1]);
        }
        rep(i, 1, n){
            if(a[i] > a[i - 1] && a[i] > a[i + 1]){
                ans -= a[i] - max(a[i - 1], a[i + 1]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}