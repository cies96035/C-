#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

void f(){
    int n, k;
    cin >> n >> k;
    char c;
    map<char, int> cnt;
    rep(i, 0, n){
        cin >> c;
        cnt[c]++;
    }
    int ans = 0;
    rrep(i, 'a', 'z'){
        ans += min(cnt[i], cnt[i + 'A' - 'a']);
        if(abs(cnt[i] - cnt[i + 'A' - 'a']) / 2 <= k){
            ans += abs(cnt[i] - cnt[i + 'A' - 'a']) / 2;
            k -= abs(cnt[i] - cnt[i + 'A' - 'a']) / 2;
        }else{
            ans += k;
            k = 0;
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