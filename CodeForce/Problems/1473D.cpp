#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define LCN(x) (x << 1)
#define RCN(x) ((x << 1) | 1)

const int MAX_N = 2e5 + 100;
const int INF = 0x3fffffff;
int t, n, m, l, r, d;

string str;
int preSum[MAX_N];
struct SEG{
    int Max, Min;
    void Init(){
        Max = -INF, Min = INF;
    }
}seg[MAX_N << 2], tmp;
void Init(int id, int l, int r){ //[l, r]
    if(l == r){
        seg[id].Max = seg[id].Min = preSum[l];
        return;
    }
    int Mid = (l + r) >> 1;
    Init(LCN(id), l, Mid);
    Init(RCN(id), Mid + 1, r);
    seg[id].Max = max(seg[LCN(id)].Max, seg[RCN(id)].Max);
    seg[id].Min = min(seg[LCN(id)].Min, seg[RCN(id)].Min);
    return;
}
void query(int id, int l, int r, int a, int b, SEG &tmp){
    if(r < a || l > b){
        return;
    }else if(a <= l && r <= b){
        tmp.Max = max(seg[id].Max, tmp.Max);
        tmp.Min = min(seg[id].Min, tmp.Min);
        return;
    }
    int Mid = (l + r) >> 1;
    query(LCN(id), l, Mid, a, b, tmp);
    query(RCN(id), Mid + 1, r, a, b, tmp);
    return;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n >> m;
        cin >> str;
        preSum[0] = 0;
        rep(i, 0, n){
            preSum[i + 1] = preSum[i] + (str[i] == '+' ? 1 : -1);
        }
        Init(1, 0, n);
        while(m--){
            tmp.Init();
            cin >> l >> r;
            d = preSum[r] - preSum[l - 1];
            query(1, 0, n, 0, l - 1, tmp);
            tmp.Max += d, tmp.Min += d;
            query(1, 0, n, r, n, tmp);
            cout << tmp.Max - tmp.Min + 1 << '\n';
        }
    }
    return 0;
}