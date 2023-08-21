#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 1e5 + 5;
// map<pll, ll> dp;
int dp[MAX_N][MAX_N];
ll st[MAX_N], gi[MAX_N];

int n;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    rep(i, 0, n){
        cin >> st[i];
    }
    rep(i, 0, n){
        cin >> gi[i];
    }
    // dp[{0, 0}] = 0;
    // rep(i, 0, n){
    //     map<pll, ll> tmpM;
    //     for(auto j : dp){
    //         pll tmp = j.first;
    //         ll ttmp;
    //         if(!dp.count({tmp.first + 1, tmp.second})){
    //             tmpM[{tmp.first + 1, tmp.second}] = st[i];
    //         }else{
    //             ttmp = max(dp[{tmp.first + 1, tmp.second}], // do nothing
    //                 dp[{tmp.first, tmp.second}] + st[i]);
    //             tmpM[{tmp.first + 1, tmp.second}] = max(
    //                 tmpM[{tmp.first + 1, tmp.second}], // do nothing
    //                 ttmp
    //             );
    //         }
            
    //         if(!dp.count({tmp.first, tmp.second + 1})){
    //             tmpM[{tmp.first, tmp.second + 1}] = -gi[i];
    //         }else{
    //             ttmp = max(dp[{tmp.first, tmp.second + 1}],
    //                 dp[{tmp.first, tmp.second}] - gi[i]);
    //             tmpM[{tmp.first, tmp.second + 1}] = max(
    //                 tmpM[{tmp.first, tmp.second + 1}], 
    //                 ttmp
    //             );
    //         }
    //     }
    //     cout << i << endl;
    //     for(auto j : tmpM){
    //         cout << j.first.first << ' ' << j.first.second << ':' << j.second << endl;
    //         dp[j.first] = max(dp[j.first], tmpM[j.first]);
    //     }
    // }
    // int ans = 0;
    // rrep(i, 1, n){
    //     if(dp[{i, i}] >= 0){
    //         ans = i;
    //     }
    // }
    // cout << ans << '\n';
    return 0;
}