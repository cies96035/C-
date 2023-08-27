#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

void f(){
    ll n, m, d;
    int a;
    map<int, int> cnt;
    ll sum = 0, ans = 0;
    int totalcnt = 0;
    cin >> n >> m >> d;
    rrep(i, 1, n){
        cin >> a;
        if(a >= 0){
            cnt[a]++;
            totalcnt++;
            sum += a;
            if(totalcnt > m){
                cnt.begin()->second--;
                totalcnt--;
                sum -= cnt.begin()->first;
                if(cnt.begin()->second == 0){
                    cnt.erase(cnt.begin()->first);
                }
            }
            ans = max(ans, sum - d * i);
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