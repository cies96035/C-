#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 100100;

int n;
ll a[MAX_N];
int ipt;
ll DP_take[MAX_N];
ll DP_not_take[MAX_N];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    rep(i, 0, n){
        cin >> ipt;
        a[ipt]++;
    }
    rep(i, 1, MAX_N){
        DP_take[i] = DP_not_take[i - 1] + i * a[i];
        DP_not_take[i] = 
        max(
            DP_take[i - 1],
            DP_not_take[i - 1]
        );
    }
    cout << DP_take[MAX_N - 1] << '\n';
    return 0;
}