#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i <= b; i++)

const int MAX_N = 4e6 + 20;
ll n, m;
ll cnt[MAX_N];
ll DP[MAX_N];
ll presum[MAX_N];
ll ans;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    DP[1] = 1;
    presum[1] = 1;
    rep(i, 2, n){
        DP[i] = presum[i - 1];
        ll si = sqrt(i), cnt = i - 1;
        rep(j, 2, si){
            DP[i] += DP[i / j];
            cnt--;
            if(j != i / j){
                DP[i] += (i / j - i / (j + 1)) * DP[j];
                cnt -= (i / j - i / (j + 1));
            }
        }
        DP[i] += DP[1] * cnt;
        DP[i] %= m;
        presum[i] = ( presum[i - 1] + DP[i] ) % m;
        presum[i] %= m;
        cout <<i << ' ' << DP[i] << ' ' << cnt << endl;
    }
    cout << DP[n] << '\n';
    return 0;
}