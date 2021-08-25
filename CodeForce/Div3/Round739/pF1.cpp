#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define rrep(i, a, b) for(int i = a; i < b; i++)

string num_to_str(ll n){
    string ans = "";
    while(n){
        ans += char('0' + n % 10);
        n /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ll t, k;
    string n;
    ll p;
    cin >> t;
    while(t--){
        cin >> n >> k;
        // n = num_to_str(t + 1000);
        // k = 2;
            string ans(n.size(), '9');
            rep(i, '0', '9'){
                rep(j, i, '9'){
                    if(k == 1 && i != j){
                        continue;
                    }
                    // cout << char(i) << (char)j << endl;
                    string tt(n.size(), '9');
                    bool flg = true;
                    rrep(g, 0, n.size()){
                        string ttt = tt;
                        ttt[g] = i;
                        rrep(d, g + 1, tt.size()){
                            ttt[d] = j;
                        }
                        if(ttt >= n){
                            tt[g] = i;
                            continue;
                        }
                        ttt[g] = j;
                        if(ttt >= n){
                            tt[g] = j;
                            continue;
                        }
                        flg = false;
                        break;
                    }
                    if(tt.size() >= n.size() && tt >= n && flg){
                        ans = min(ans, tt);
                    }
                }
            }
            cout << ans << '\n';
    }
    return 0;
}