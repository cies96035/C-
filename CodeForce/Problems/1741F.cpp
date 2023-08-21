#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define f0r(i, n) for(int i = 0; i < n; i++)
#define f1r(i, n) for(int i = 1; i <= n; i++)

using ll = long long;
using pll = pair<ll, ll>;
const int MAX_N = 2e5 + 5;
const ll INF = 1e15;

typedef tree<
        pll, 
        null_type, 
        less<pll>, 
        rb_tree_tag, 
        tree_order_statistics_node_update
    > ordered_set;
ll t, n;
struct SEG{
    ll l, r, c, id;
    bool operator<(const SEG &x){
        if(c != x.c) return c < x.c;
        if(l != x.l) return l < x.l;
        if(r != x.r) return r < x.r;
        if(id != x.id) return id < x.id;
        return false;
    }
}seg[MAX_N];
ll ans[MAX_N];

void FindAns(bool order){
    ordered_set e, s;
    queue<SEG> seg_tmp;
    e.insert({-INF, 0});
    s.insert({INF, 0});
    ll idx, preidx, first_color = order ? seg[1].c : seg[n].c;
    ll cnt = 0;
    f1r(i, n){
        idx = order ? i : n - i + 1;
        preidx = order ? idx - 1 : idx + 1;

        if(seg[idx].c != first_color){
            if(seg[idx].c != seg[preidx].c){ // color change
                while(!seg_tmp.empty()){
                    e.insert({seg_tmp.front().r, seg_tmp.front().id});
                    s.insert({seg_tmp.front().l, seg_tmp.front().id});
                    seg_tmp.pop();
                    cnt++;
                }
            }

            ans[ seg[idx].id ] = min( // closet left segment
                ans[ seg[idx].id ], 
                seg[idx].l - (--e.upper_bound({seg[idx].l, INF}))->first
            );

            ans[ seg[idx].id ] = min( // closet right segment
                ans[ seg[idx].id ], 
                s.lower_bound({seg[idx].r, -INF})->first - seg[idx].r
            );

            if((ll)e.order_of_key({seg[idx].l + 1, -INF}) -
            (ll)s.order_of_key({seg[idx].r + 1, -INF}) <= 0){ // cross
                ans[seg[idx].id] = 0;
            }
        }
        seg_tmp.push(seg[idx]);
    }
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        f1r(i, n){
            cin >> seg[i].l >> seg[i].r >> seg[i].c;
            seg[i].id = i;
            ans[i] = INF;
        }
        sort(seg + 1, seg + n + 1); // sort by color

        FindAns(true); // 1, 2, 3, ..., n
        FindAns(false); // n, n - 1, ..., 1
        f1r(i, n){
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}