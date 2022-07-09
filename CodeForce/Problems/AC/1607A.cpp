#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

int t;
int table[256];
string s;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> s;
        rep(i, 0, 26){
            table[s[i]] = i;
        }
        cin >> s;
        int ans = 0;
        rep(i, 1, s.size()){
            ans += abs(table[s[i]] - table[s[i - 1]]);
        }
        cout << ans << '\n';
    }
    return 0;
}