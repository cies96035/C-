#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i <= b; i++)

const int MAX_N = 2e5 + 5;
int n, q, x, a, b, u; 
ll BIT[MAX_N];
void modify(int x, int val){
    while(x < MAX_N){
        BIT[x] += val;
        x += x & -x;
    }
    return ;
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
        cin >> x;
        modify(i, x);
        modify(i + 1, -x);
    }
    while(q--){
        cin >> x;
        if(x == 1){
            cin >> a >> b >> u;
            modify(a, u);
            modify(b + 1, -u);
        }else{
            cin >> u;
            cout << query(u) << '\n';
        }
    }
    return 0;
}