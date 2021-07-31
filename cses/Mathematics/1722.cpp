#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MOD = 1000000007;
ll n;
void matrixMul(ll a[2][2], ll b[2][2]){
    ll tmp[2][2];
    rep(i, 0, 2){
        rep(j, 0, 2){
            tmp[i][j] = 0;
            rep(k, 0, 2){
                tmp[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    rep(i, 0, 2){
        rep(j, 0, 2){
            a[i][j] = tmp[i][j] % MOD;
        }
    }
}
ll qpow(ll b){
    ll a[2][2] = {
        {1, 1},
        {1, 0}
    };
    ll ans[2][2] = {
        {1, 0},
        {0, 1}
    };
    while(b){
        if(b & 1){
            matrixMul(ans, a);
        }
        matrixMul(a, a);
        b >>= 1;
    }
    return ans[1][0] ; 
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    cout << qpow(n) << '\n';
    return 0;
}