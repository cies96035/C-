#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i <= b; i++)

const int MOD = 1e9 + 7;
const int MAX_N = 1e6 + 5;

int n;
ll DP[MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    DP[0] = 1;
    rep(i, 1, n){
        rep(j, 1, min(i, 6)){
            DP[i] += DP[i - j];
        }
        DP[i] %= MOD;
    }
    cout << DP[n] << '\n';
    return 0;
}