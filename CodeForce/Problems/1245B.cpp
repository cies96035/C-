#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t;
int n;
int a, b, c;
int cnt;
string s, ans;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n >> a >> b >> c >> s;
        cnt = 0;
        ans = "";
        rep(i, 0, s.size()){
            if(s[i] == 'S' && a){
                ans += 'R';
                a--;
                cnt++;
            }else if(s[i] == 'R' && b){
                ans += 'P';
                b--;
                cnt++;
            }else if(s[i] == 'P' && c){
                ans += 'S';
                c--;
                cnt++;
            }else{
                ans += '0';
            }
        }
        if( n <= (cnt << 1) ){
            cout << "YES\n";
            rep(i, 0, s.size()){
                if(ans[i] == '0'){
                    if(a){
                        ans[i] = 'R';
                        a--;
                    }else if(b){
                        ans[i] = 'P';
                        b--;
                    }else{
                        ans[i] = 'S';
                    }
                }
            }
            cout << ans << '\n';
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}