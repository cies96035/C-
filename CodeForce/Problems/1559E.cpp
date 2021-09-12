#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
const int M = 998244353;
const int MAX_N = 55;
const int MAX_M = 1e5 + 5;
int n, m;
int DP[MAX_N][MAX_M];
int a[MAX_N][2];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    rep(i, 0, n){
        cin >> a[i][0] >> a[i][1];
    }
    rrep(i, a[0][0], a[0][1]){
        DP[0][i] = 1;
    }
    ll sum;
    rep(i, 0, n){
        sum = 0;
        rrep(j, 1, m){
            sum += DP[i][j];
        }
        cout << sum << endl;
        DP[i + 1][1] = sum;
        rrep(j, a[i][0], a[i][1]){
            // DP[i + 1][j] = sum;
            for(int k = j; k <= m; k += j){
                DP[i + 1][j] += DP[i][k];
            }
            cout << i << ':' << DP[i + 1][j] << endl;
        }
    }
    cout << DP[n][1] << '\n';
    return 0;
}