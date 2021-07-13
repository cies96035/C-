#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_P = 45000;
int t;
ll a, b;
ll diff;
ll pres[MAX_P];
int ans;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    rep(i, 1, MAX_P){
        pres[i] = pres[i - 1] + i;
    }
    cin >> t;
    while(t--){
        cin >> a >> b;
        diff = abs(a - b);
        ans = lower_bound(pres, pres + MAX_P, diff) - pres;
        while((pres[ans] + diff) & 1){
            ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}