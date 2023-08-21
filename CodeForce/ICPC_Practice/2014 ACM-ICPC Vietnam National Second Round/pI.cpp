#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define X first
#define Y second
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_M = 1e3 + 5;
const int MAX_N = 1e3 + 5;
int t, m, n;
char ma[MAX_M][MAX_N];
int sum[MAX_M][MAX_N];
int ans;
pll dir[4][2] = {
    {   pll{-1, 0},
        pll{0, -1}  },
    {   pll{0, 1},
        pll{-1, 0}  },
    {   pll{1, 0},
        pll{0, 1}  },
    {   pll{0, -1},
        pll{1, 0}  }
};
inline void pos_add(pll &a, pll b){
    a.X += b.X;
    a.Y += b.Y;
}
inline bool out_bound(pll cur){
    return !(cur.X >= 1 && cur.X <= m && cur.Y >= 1 && cur.Y <= n);
}
void f(pll cur, bool nb, int cnt, const int mode){
    if(out_bound(cur)){
        return;
    }
    if(ma[cur.X][cur.Y] == '0'){
        cnt = 0;
    }else{
        cnt++;
    }
    if(nb == 0){
        sum[cur.X][cur.Y] += cnt;
    }
    pos_add(cur, dir[mode][nb]);
    f(cur, !nb, cnt, mode);
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        memset(sum, 0, sizeof(sum));
        cin >> m >> n;
        rrep(i, 1, m){
            rrep(j, 1, n){
                cin >> ma[i][j];
            }
        }
        //m0
        rrep(i, 1, m){
            f({i, n}, 0, 0, 0);
        }
        rrep(j, 1, n - 1){
            f({m, j}, 0, ma[m][j + 1] == '1', 0);
        }
        //m1
        rrep(i, 1, m - 1){
            f({i, 1}, 0, ma[i + 1][1] == '1', 1);
        }
        rrep(j, 1, n){
            f({m, j}, 0, 0, 1);
        }
        //m2
        rrep(i, 1, m){
            f({i, 1}, 0, 0, 2);
        }
        rrep(j, 2, n){
            f({1, j}, 0, ma[1][j - 1] == '1', 2);
        }
        //m3
        rrep(i, 2, m){
            f({i, n}, 0, ma[i - 1][n] == '1', 3);
        }
        rrep(j, 1, n){
            f({1, j}, 0, 0, 3);
        }
        ans = 0;
        rrep(i, 1, m){
            rrep(j, 1, n){
                // cout << sum[i][j] << ' ';
                ans = max(ans, sum[i][j]);
            }
            // cout << endl;
        }
        if(ans != 0){
            cout << ans - 3 << '\n';
        }else{
            cout << 0 << '\n';
        }
    }
    return 0;
}