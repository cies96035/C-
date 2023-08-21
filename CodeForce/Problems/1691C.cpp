#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

int t, n, k;
string str;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n >> k >> str;
        int fo = -1, lo = -1, ans = 0;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '1'){
                ans += 11;
                lo = i;
                if(fo == -1){
                    fo = i;
                }
            }
        }
        if(fo != -1){
            if(k >= n - 1 - lo){ // ...1
                k -= n - 1 - lo;
                ans -= 10;
                if(fo == lo) k = -1;
            }
            if(lo < fo) k++;
            if(k >= fo){  // 1...
                ans--;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}