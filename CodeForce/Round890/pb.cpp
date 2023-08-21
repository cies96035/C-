#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

int n;
void f(){
    cin >> n;
    ll a;
    ll cnt = 0, sum = 0;
    rep(i, 0, n){
        cin >> a;
        if(a != 1) cnt++;
        sum += a;
    }
    sum -= cnt;
    if(n > 1 && sum >= (n - cnt) * 2){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
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