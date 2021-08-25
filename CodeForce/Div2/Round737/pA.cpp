#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 1e5 + 5;;
const int INF = 0x3fffffff;
int t, n;
ld preSum[MAX_N];
ld ans;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        cin >> preSum[0];
        ld M = preSum[0];
        rep(i, 1, n){
            cin >> preSum[i];
            M = max(M, preSum[i]);
            preSum[i] += preSum[i - 1];
        }
        ans = - INF;
        rep(i, 1, n){
            // cout << i << ' ' << preSum[i - 1] << ' ' << preSum[n - 1] - preSum[i - 1] << endl;
            // cout << i << ' ' << n - i << endl;
            ans = max(ans, 
            preSum[i - 1] / i + 
            (preSum[n - 1] - preSum[i - 1]) / (n - i));
        }
        ans = M + (preSum[n - 1] - M) / (n - 1);
        cout << fixed << setprecision(10) << ans << '\n';
    }
    return 0;
}