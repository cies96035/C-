#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const ll MOD = 1e9 + 7;
const int MAX_N = 1e6 + 5;
ll ans[2][MAX_N]; 
/*  ans[0] : end with [  ]
    ans[1] : end with [][]  */
ll t, n;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ans[0][1] = 1;
    ans[1][1] = 1;
    rep(i, 2, MAX_N){
        ans[0][i] = ( ans[0][i - 1] * 2 + ans[1][i - 1] ) % MOD;
        ans[1][i] = ( ans[1][i - 1] * 4 + ans[0][i - 1] ) % MOD;
    }
    cin >> t;
    while(t--){
        cin >> n;
        cout << ( ans[0][n] + ans[1][n] ) % MOD << '\n';
    }
    return 0;
}