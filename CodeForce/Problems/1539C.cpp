#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 200200;
ll cnt;
ll n, k, x;
ll a[MAX_N];
ll K[MAX_N];
bool close(ll a, ll b, ll X){
    return b - a <= X;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> k >> x;
    rep(i, 0, n){
        cin >> a[i];
    }
    cnt = n;
    sort(a, a + n);
    for(int i = 1; i < n; i++){
        K[i] = (a[i] - a[i - 1] - 1) / x;
        if(K[i] < 0){
            K[i] = 0;
        }
    }
    sort(K, K + n);
    for(int i = 1; i < n; i++){
        if(K[i] <= k){
            k -= K[i];
            cnt--;
        }else{
            break;
        }
    }
    cout << cnt << '\n';
    return 0;
}