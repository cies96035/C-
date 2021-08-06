#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t, n;
ll aed, a, ans;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        ans = 0;
        cin >> n;
        cin >> aed; n--;
        rep(i, 0, n){
            cin >> a;
            if(max(a, aed) * min(a, aed) > ans){
                ans = max(a, aed) * min(a, aed);
            }
            aed = a;
        }
        cout << ans << '\n';
    }
    return 0;
}