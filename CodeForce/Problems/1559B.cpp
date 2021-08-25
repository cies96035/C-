#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t, n;
string str, s;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n >> s;
        rep(i, 0, n){
            if(s[i] != '?'){
                bool flg = (s[i] == 'R');
                for(int j = i - 1; j >= 0; j--){
                    if(flg ^ ((i - j) & 1)){
                        s[j] = 'R';
                    }else{
                        s[j] = 'B';
                    }
                }
                for(int j = i + 1; j < s.size(); j++){
                    if(s[j] == '?'){
                        if(s[j - 1] == 'B'){
                            s[j] = 'R';
                        }else{
                            s[j] = 'B';
                        }
                    }
                }
                break;
            }
        }
        if(s[0] == '?'){
            rep(i, 0, n){
                if(i & 1){
                    s[i] = 'R';
                }else{
                    s[i] = 'B';
                }
            }
        }
        cout << s << '\n';
    }
    return 0;
}