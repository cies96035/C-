#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int INF = 0x3fffffff;
#define LCN(x) (x << 1)
#define RCN(x) ( (x << 1) + 1)
const int MAX_N = 3e5 + 5;
const int MAX_M = 6e5 + 5;

int maxseg[MAX_M << 2], lazy[MAX_M << 2];
struct SEG{
    int l, r, w;
    bool operator <(const SEG &x){
        return w < x.w;
    }
}seg[MAX_N];

inline void push_down(int id){
    maxseg[LCN(id)] += lazy[id];
    lazy[LCN(id)] += lazy[id];
    maxseg[RCN(id)] += lazy[id];
    lazy[RCN(id)] += lazy[id];
    lazy[id] = 0;
}

void modify(int id, int l, int r, int a, int b, int val){
    if(a <= l && r <= b){ // all in_bound
        maxseg[id] += val, lazy[id] += val; // modify value + lazy tag
        return;
    }else if(r < a || l > b){ // all out_bound
        return;
    }
    push_down(id); // push_down lazy tag

    int mid = (l + r) >> 1;
    modify(LCN(id), l, mid, a, b, val);
    modify(RCN(id), mid + 1, r, a, b, val);
    maxseg[id] = max( maxseg[LCN(id)], maxseg[RCN(id)] );
    return;
}


int query(int id, int l, int r, int a, int b){
    if(a <= l && r <= b){
        return maxseg[id];
    }else if(r < a || l > b){
        return -INF;
    }
    push_down(id);
    int mid = (l + r) >> 1;
    return max(
        query(LCN(id), l, mid, a, b), 
        query(RCN(id), mid + 1, r, a, b));
}

int ans[MAX_N], ansA[MAX_N], MaxAnsId = 0;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    map<int, int> mi;
    set<int> pos;
    int n, m;
    cin >> n >> m;
    vector<int, pair<int, int> > tt(n + 1);
    for(int i = 0, x, a, b; i < m; i++){
        cin >> x >> a >> b;
        tt[x].emplace_back({a, b});
        pos.insert(a);
        pos.insert(b);
    }
    int ____ = 0;
    for(auto pi : pos){
        mi[pi] = ____++;
    }
    for(int i = 1; i <= n; i++){
    }

    return 0;
}