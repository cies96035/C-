#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 3e5 + 5;
const int MAX_M = 1e6 + 5;
const int INF = 0x3fffffff;
#define LCN(x) (x << 1)
#define RCN(x) ( (x << 1) + 1)

int n, m;
int minseg[MAX_M << 2], lazy[MAX_M << 2];
struct SEG{
    int l, r, w;
    bool operator <(const SEG &x){
        return w < x.w;
    }
}seg[MAX_N];

inline void push_down(int id){
    minseg[LCN(id)] += lazy[id];
    lazy[LCN(id)] += lazy[id];
    minseg[RCN(id)] += lazy[id];
    lazy[RCN(id)] += lazy[id];
    lazy[id] = 0;
}

void modify(int id, int l, int r, int a, int b, int val){
    if(a <= l && r <= b){ // all in_bound
        minseg[id] += val, lazy[id] += val; // modify value + lazy tag
        return;
    }else if(r < a || l > b){ // all out_bound
        return;
    }
    push_down(id); // push_down lazy tag

    int mid = (l + r) >> 1;
    modify(LCN(id), l, mid, a, b, val);
    modify(RCN(id), mid + 1, r, a, b, val);
    minseg[id] = min( minseg[LCN(id)], minseg[RCN(id)] );
    return;
}

int query(int id, int l, int r, int a, int b){
    if(a <= l && r <= b){
        return minseg[id];
    }else if(r < a || l > b){
        return INF;
    }
    push_down(id);
    int mid = (l + r) >> 1;
    return min(
        query(LCN(id), l, mid, a, b), 
        query(RCN(id), mid + 1, r, a, b));
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    rep(i, 0, n){
        cin >> seg[i].l >> seg[i].r >> seg[i].w;
        seg[i].r--; // [l, r) == [l, r - 1]
    }
    m--;//[l, m - 1]
    sort(seg, seg + n);
    
    int l = 0, r = -1, Min = INF;
    while(r < n){ //[l, r]
        if(!minseg[1]){ // not connect
            r++;
            modify(1, 1, m, seg[r].l, seg[r].r, 1);
        }else{
            Min = min(Min, seg[r].w - seg[l].w);
            modify(1, 1, m, seg[l].l, seg[l].r, -1);
            l++;
        }
    }
    cout << Min << '\n';
    return 0;
}