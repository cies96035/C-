#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i <= b; i++)

const int MAX_N = 200005;
int n, q;
int cs, a, b;
int x[MAX_N];
ll BIT[MAX_N];
void update(int x, int val){
    while(x < MAX_N){
        BIT[x] += val;
        x += x & -x;
    }
    return;
}
ll query(int x){
    ll ans = 0;
    while(x){
        ans += BIT[x];
        x -= x & -x;
    }
    return ans;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> q;
    rep(i, 1, n){
        cin >> x[i];
        update(i, x[i]);
    }
    while(q--){
        cin >> cs >> a >> b;
        if(cs == 1){
            update(a, b - x[a]);
            x[a] = b;
        }else{
            cout << query(b) - query(a - 1) << '\n';
        }
    }
    return 0;
}