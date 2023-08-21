#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

int t, n, a;
int cnt, ans, used, num;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        cnt = n;
        rep(i, 0, n){
            cin >> a;
            while(a % 2 == 0){
                cnt--;
                a /= 2;
            }
        }
        ans = 0, used = 0;
        rvep(i, 20, 0){
            if(cnt <= 0){
                break;
            }
            auto tmp = ((n >> i) - used);
            if(cnt <= tmp * i){
                ans += (cnt - 1) / i + 1;
                cnt = 0;
            }else{
                cnt -= tmp * i;
                ans += tmp;
                used += tmp;
            }
        }
        
        if(cnt > 0){
            cout << -1 << '\n';
        }else{
            cout << ans << '\n';
        }

    }
    return 0;
}