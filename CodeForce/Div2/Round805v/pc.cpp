/*
1 1 3
1 2 4

*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_M = 2e5 + 5;
ll t;
ll n, m;
ll tasks[MAX_M];
ll arr[MAX_M];

bool testwork(ll x){ // sum(n - x, n>=x) >= 2 * sum(x - n, n < x) wrong
    ll cnt = 0;
    rep(i, 0, x)
        cnt -= (x - i) / 2 * arr[i];
    rrep(i, x, m)
        cnt += (i - x) * arr[i];
    return cnt <= 0;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n >> m;
        
        rrep(i, 0, m) // Init
            arr[i] = 0;
        rrep(i, 0, n)
            tasks[i] = 0;

        int ipt;
        rep(i, 0, m){
            cin >> ipt;
            tasks[ipt]++;
        }
        int cnt = 0;
        rrep(i, 1, n){
            arr[tasks[i]]++;
        }
        ll l = 1, r = m + 1, mid;
        while(l < r){
            mid = (l + r) / 2;
            // cout << l << ' ' << r << ' ' << mid << endl;
            if(!testwork(mid)){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        cout << l << '\n';
        // cout << "a ";
        // rrep(i, 1, 10){
        //     cout << testwork(i) << ' ';
        // }cout << endl;
        // cout << "b ";
    }
    return 0;
}