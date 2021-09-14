#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

ll ans, n;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    rep(i, 0, 60){
        if(n & (1LL << i)){
            ans += (n >> (i + 1) << i) + ((n & ((1LL << i) - 1)) + 1);
        }else{
            ans += (n >> (i + 1) << i);
        }
    }
    cout << ans << '\n';
    
    return 0;
}