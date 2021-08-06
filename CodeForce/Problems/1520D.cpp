#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 2e5 + 5;
int t, n, a;
ll ans;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        ans = 0;
        map<int, int> cnt;
        cin >> n;
        rep(i, 0, n){
            cin >> a;
            ans += cnt[a - i];
            cnt[a - i]++;
        }
        cout << ans << '\n';
    }
    return 0;
}