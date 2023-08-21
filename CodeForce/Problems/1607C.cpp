#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 5;
const int INF = 0x3fffffff;
int t, n;
ll arr[MAX_N];
ll presum[MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        rep(i, 0, n){
            cin >> arr[i];
        }
        sort(arr, arr + n);

        ll ans = arr[0];
        rep(i, 1, n){
            ans = max(ans, arr[i] - arr[i - 1]);
        }
        cout << ans << '\n';
        // presum[0] = 0;
        // rep(i, 0, n){
        //     presum[i + 1] = presum[i] + arr[i];
        // }

        // int l = 0, r = n;
        // while(l < r){

        // }
    }
    return 0;
}