#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

void f(){
    int n;
    cin >> n;
    ll sum = 0, cnt = 0, x;
    bool flg = true;
    rep(i, 0, n){
        cin >> x;
        if(!flg & x > 0){
            flg = true;
        }else if(flg && x < 0){
            flg = false;
            cnt++;
        }
        sum += abs(x);
    }
    cout << sum << ' ' << cnt << '\n';
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