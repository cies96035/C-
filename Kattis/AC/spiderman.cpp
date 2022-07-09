#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using plb = pair<ll, bool>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_M = 50;
const int MAX_S = 1050;

plb dp[MAX_M][MAX_S];// true U false D
int S[MAX_M];
int N, M;
void Init(int m){
    rrep(i, 0, m){
        rep(j, 0, MAX_S){
            dp[i][j] = {-1, false};
        }
    }
    dp[0][0] = {0, true};
    return;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    while(N--){
        cin >> M;

        Init(M);
        rep(i, 0, M){
            cin >> S[i];
        }

        rep(i, 0, M){
            rep(j, S[i], MAX_S){
                if(dp[i][j - S[i]].first != -1){
                    dp[i + 1][j] = {max( dp[i][j - S[i]].first, (ll)j ), true};
                }
            }
            
            rep(j, 0, MAX_S - S[i]){
                if(dp[i][j + S[i]].first != -1){
                    if(dp[i][j + S[i]].first < dp[i + 1][j].first || dp[i + 1][j].first == -1){
                        dp[i + 1][j] = {dp[i][j + S[i]].first, false};
                    }
                }
            }
        }
        
        if(dp[M][0].first == -1){
            cout << "IMPOSSIBLE\n";
        }else{
            string ans;
            int pos = 0;
            rvep(i, M, 1){
                if(dp[i][pos].second){
                    ans += 'U';
                    pos -= S[i - 1];
                }else{
                    ans += 'D';
                    pos += S[i - 1];
                }
            }
            reverse(ans.begin(), ans.end());
            cout << ans << '\n';
        }
    }
    return 0;
}