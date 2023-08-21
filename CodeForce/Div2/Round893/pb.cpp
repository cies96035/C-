#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)


/*

8 3 2
3 5 8

1 2 3 4 5 6 7 8 9 10 11
X   X   X   I   X       X
X   X   I   I   X       X


*/
const int MAX_N = 1e5 + 5;
ll s[MAX_N];
ll n, m, d;
int count(int i, int j){
    return (s[i] - s[j] - 1) / d;
}
void f(){
    cin >> n >> m >> d;
    ll ans = 0;
    s[0] = 1;
    rrep(i, 1, m){
        cin >> s[i];
        ans++;
        ans += count(i, i - 1);
    }
    if(s[1] != 1) ans++;
    s[m + 1] = n + 1;
    ans += count(m + 1, m);

    ll cnt = 0, Min = 0;
    rrep(i, 1, m){ // remove i
        ll t = count(i + 1, i - 1);
        t -= (s[i] - s[i - 1] - 1) / d + (s[i + 1] - s[i] - 1) / d;
        if(s[i] != 1) t--;
        if(t < Min){
            Min = t;
            cnt = 1;
        }else if(t == Min){
            cnt++;
        }
    }
    cout << ans + Min << ' ' << cnt << '\n';

    
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