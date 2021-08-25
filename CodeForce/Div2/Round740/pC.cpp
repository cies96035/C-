#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 1e5 + 5;
ll t, n, k;
pii a[MAX_N];
ll Max;
ll ipt;
bool test(ll x){
    rep(i, 0, n){
        if(x < a[i].first){
            return false;
        }else{
            x += a[i].second;
        }
    }
    return true;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        rep(i, 0, n){
            cin >> k;
            Max = 0;
            rep(j, 0, k){
                cin >> ipt;
                Max = max(Max, ipt - j + 1);
            }
            a[i] = {Max, k};
            // cout << a[i].first << ' ' << a[i].second << ' ';
        }
        // cout << endl;
        sort(a, a + n);
        ll l = 0, r = 1e10, mid;
        while(l < r){
            mid = (l + r) >> 1;
            if(test(mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        cout << l << '\n';
    }
    return 0;
}