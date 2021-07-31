#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, a, b) for(int i = a; i < b; i++)

ll n, k;
ll a[20];
ll sum(ll val, ll t){
    if(t == k){
        if(val == 1){
            return 0;
        }
        return n / val;
    }
    if(val * a[t] % a[t]){ //overflow
        return -sum(val, t + 1);
    }
    return sum(val * a[t], t + 1) - sum(val, t + 1);
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> k;
    rep(i, 0, k){
        cin >> a[i];
    }
    cout << abs(sum(1, 0)) << '\n';
    return 0;
}