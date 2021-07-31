#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i <= b; i++)

const int MAX_N = 200005;
const int INF = 0x3fffffff;
#define LCN(x) (x << 1)
#define RCN(x) ((x << 1) | 1)

int n, q, a, b, k;

ll seg[MAX_N << 2];
ll arr[MAX_N];
ll build(ll id, ll l, ll r){
    if(l == r){
        return seg[id] = arr[l];
    }else{
        ll Mid = (l + r) >> 1;
        return seg[id] = min(
            build(LCN(id), l, Mid),
            build(RCN(id), Mid + 1, r) );
    }
}
// modify posth val to newval
ll modify(ll id, ll l, ll r, const ll &pos, const ll &newval){
    if(r < pos || pos < l){ // out_bound
        return seg[id]; 
    }else if(l == r){ // deepest
        return arr[pos] = seg[id] = newval;
    }else{
        ll Mid = (l + r) / 2;
        return seg[id] = min( 
            modify(LCN(id), l, Mid, pos, newval), 
            modify(RCN(id), Mid + 1, r, pos, newval) );
    }
}
// query [a, b]
ll query(ll id, ll l, ll r, const ll &a, const ll &b){
    if(r < a || b < l){ // out_bound (do nothing)
        return INF;
    }else if(a <= l && r <= b){ // contain range, return
        return seg[id];
    }else{ // continue query
        ll Mid = (l + r) / 2;
        return min(
            query(LCN(id), l, Mid, a, b),
            query(RCN(id), Mid + 1, r, a, b) );
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> q;
    rep(i, 1, n){
        cin >> arr[i];
    }
    build(1, 1, n);
    while(q--){
        cin >> k >> a >> b;
        if(k == 1){
            modify(1, 1, n, a, b);
        }else{
            cout << query(1, 1, n, a, b) << '\n';
        }
    }
    return 0;
}