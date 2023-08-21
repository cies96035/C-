#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

void f(){
    int n;
    cin >> n;
    string str;
    ll ans = 0;
    unordered_map<int, int> scnt[26];
    rep(i, 0, n){
        int cnt[26] = {0};
        cin >> str;
        for(auto c : str) cnt[c - 'a']++;
        int num = 0;
        rep(i, 0, 26){
            num |= (cnt[i] & 1) << (i);
        }
        rep(i, 0, 26){
            if(cnt[i] != 0)continue;
            ans += scnt[i][((1 << 26) - 1) ^ num ^ (1 << i)];
        }
        rep(i, 0, 26){
            if(cnt[i] == 0){
                scnt[i][num]++;
            }
        }
    }
    cout << ans << '\n';

}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while(t--) f();
    
    return 0;
}