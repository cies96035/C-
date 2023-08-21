#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

int t, n;
char c;
string str;
int ans, lg , lc;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n >> c;
        cin >> str;
        if(c == 'g'){
            cout << 0 << '\n';
            continue;
        }
        ans = 0;
        lc = 0x3fffffff, lg = -1;

        rvep(i, n - 1, 0){
            if(str[i] == 'g'){
                lg = i;
            }
            if(str[i] == c){
                ans = max(ans, lg - i);
                if(lg == -1){
                    lc = i;
                }
            }
        }
        ans = max(ans, n - lc + lg);
        cout << ans << '\n';
    }
    return 0;
}