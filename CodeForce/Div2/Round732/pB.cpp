#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_M = 100500;
int t, n, m;
int cnt[MAX_M][26];
char c;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n >> m;
        rep(i, 0, n){
            rep(j, 0, m){
                cin >> c;
                cnt[j][c - 'a']++;
            }
        }
        rep(i, 1, n){
            rep(j, 0, m){
                cin >> c;
                cnt[j][c - 'a']--;
            }
        }
        rep(i, 0, m){
            rep(j, 0, 26){
                if(cnt[i][j]){
                    cout << char(j + 'a');
                    cnt[i][j]--;
                }
            }
        }
        cout << '\n' << flush;
    }
    return 0;
}