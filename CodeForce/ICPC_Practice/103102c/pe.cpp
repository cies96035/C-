
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<int, int>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)
const int MAX_N = 5e5 + 5;
int n, a[MAX_N];
int presum[MAX_N][3][3];
stack<int> sa, sb, saa, sbb;
int cnta, cntb;
int cnt[3][3];
pll sub(pll x, pll y){
    return pll{x.first - y.first, x.second - y.second};
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    // pll cnt = {0, 0};
    // cnt[0][0] = 1;
    ll ans = 0;
    rrep(i, 1, n){
        int tmp[3][3];
        rep(j, 0, 3)rep(k, 0, 3)tmp[j][k] = 0;
        cin >> a[i];
        a[i] %= 3;

        // if(a[i] == 1) cnt.first++, cnt.first %= 3;
        // else if(a[i] == 2) cnt.second++, cnt.second %= 3;
        rep(j, 0, 3){
            rep(k, 0, 3){
                tmp[(j + k * a[i]) % 3][(k + a[i]) % 3] += cnt[j][k];
                // tmp[i][j] = cnt[i + cnt[i][j]][j * a[i] % 3];
                // presum[i][j][k] = presum[i - 1][j][k] + (cnt == pll{j, k});
            }
        }
        tmp[0][a[i]]++;
        rep(j, 0, 3){
            rep(k, 0, 3){
                cnt[j][k] = tmp[j][k];
                // cout << cnt[j][k] << ' ';
            }
            // cout << endl;
            ans += cnt[0][j];
        }
        // cout << endl;
    }
    // rrep(i, 1, n){
    //     static pll ccnt = {0, 0};
    //     static const pll dict[3][3] = {
    //         pll{0, 0}, pll{0, 1}, pll{1, 0},
    //         pll{0, 0}, pll{2, 0}, pll{2, 1},
    //         pll{0, 0}, pll{0, 2}, pll{1, 2}
    //     };
    //     if(a[i] == 0){
    //         rep(j, 0, 3){
    //             rep(k, 0, 3){
    //                 if(sub(cnt, presum[i][j][k]) == dict[i][j])
    //                 presum[i][j][k] = presum[i - 1][j][k] + (cnt == pll{j, k});
    //             }
    //         }
    //         ans += 
    //     }
    //     if(a[i] == 1){
    //         ans += presum[n][]
    //     }
    // }
    // ll ans = 0;
    // rvep(i, n, 2){ // [1, i - 1], [i, n]
    //     cnta += (a[i] == 1);
    //     cntb += (a[i] == 2);
    //     if(cnta % 3 == 0 && cntb % 3 == 0){
    //         ans += 
    //     }
    // }
    cout << ans << '\n';
    return 0;
}