#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define X first
#define Y second
#define LCN(x) (x << 1)
#define RCN(x) (x << 1 | 1)

const int MAX_N = 3e5 + 5;

vector<pii> vpii[MAX_N];
struct SEG{
    pii val = {0, 0}, lazy = {0, 0};
}seg[MAX_N << 3];

inline void push_down(int id){// must push down before visit LC, RC
    seg[LCN(id)].val = max( seg[LCN(id)].val, seg[id].lazy );
    seg[LCN(id)].lazy = max( seg[LCN(id)].lazy, seg[id].lazy );
    seg[RCN(id)].val = max( seg[RCN(id)].val, seg[id].lazy );
    seg[RCN(id)].lazy = max( seg[RCN(id)].lazy, seg[id].lazy );
    seg[id].lazy = {0, 0};
}
void range_modify(int id, int l, int r, const int a, const int b, const pii val){ // change [a, b] to val
    if(r < a || l > b){ // out bound
    }else if(a <= l && r <= b){ // in bound
        seg[id].val = val; // update [l, r]
        seg[id].lazy = val; // push down later
    }else{
        push_down(id); // push lazy tag
        int Mid = (l + r) >> 1;
        range_modify(LCN(id), l, Mid, a, b, val);
        range_modify(RCN(id), Mid + 1, r, a, b, val);

        seg[id].val = max( seg[LCN(id)].val, seg[RCN(id)].val ); // update from children
    }
}
void query(int id, int l, int r, const int a, const int b, pii &ans){
    if(r < a || l > b){
    }else if(a <= l && r <= b){
        ans = max(ans, seg[id].val); //query ans
    }else{
        push_down(id); //push down lazy tag
        int Mid = (l + r) >> 1;
        query(LCN(id), l, Mid, a, b, ans);
        query(RCN(id), Mid + 1, r, a, b, ans);
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;

    int a, b, c;
    vector<int> vi;

    rep(i, 0, m){
        cin >> a >> b >> c;
        vpii[a].push_back({b, c});
        vi.push_back(b), vi.push_back(c);
    }
    sort( all(vi) );
    vi.erase( unique( all(vi) ), vi.end() );

    rrep(i, 1, n){
        for(auto &j : vpii[i]){
            j.X = lower_bound(all(vi), j.X) - vi.begin() + 1;
            j.Y = lower_bound(all(vi), j.Y) - vi.begin() + 1;
        }
    }

    vector<int> parent(n + 1);
    pii ans;
    rrep(i, 1, n){
        ans = {0, 0};
        for(auto p : vpii[i]){
            query(1, 1, vi.size(), p.X, p.Y, ans);
        }

        parent[i] = ans.Y;
        ans = {ans.X + 1, i};

        for(auto p : vpii[i]){
            range_modify(1, 1, vi.size(), p.X, p.Y, ans);
        }
    }

    vector<int> vi2;

    ans = {0, 0};
    query(1, 1, vi.size(), 1, vi.size(), ans);

    while(ans.Y != 0){
        vi2.emplace_back(ans.Y);
        ans.Y = parent[ans.Y];
    }
    
    cout << n - vi2.size() << '\n';
    for(int i = 1, j = vi2.size() - 1; i <= n; i++){
        if(j >= 0 && vi2[j] == i){
            j--;
        }else{
            cout << i << ' ';
        }
    }
    cout << '\n';
    return 0;
}