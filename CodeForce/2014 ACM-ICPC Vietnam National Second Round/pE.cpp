#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define LCN(x) (x << 1)
#define RCN(x) (x << 1 | 1)
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

ll qpow(ll b, ll n, ll m){
    ll ans = 1;
    while(n){
        if(n & 1){
            ans *= b, ans %= m;
        }
        b *= b, b %= m;
        n >>= 1;
    }
    return ans;
}

const int MAX_N = 5e4 + 5;
const int MAX_X = 152;
const int MAX_P = 40;
ll seg[MAX_P][MAX_N << 2], lazy[MAX_P][MAX_N << 2];
void Init(int id, int l, int r){
    rep(i, 0, MAX_P){
        seg[i][id] = lazy[i][id] = 0;
    }
    if(l == r){
        return;
    }
    int Mid = (l + r) >> 1;
    Init(LCN(id), l, Mid);
    Init(RCN(id), Mid + 1, r);
}
void push_down(int id, int l, int r, const int X){
    seg[X][id] += lazy[X][id] * (r - l + 1);
    if(l != r){
        lazy[X][LCN(id)] += lazy[X][id];
        lazy[X][RCN(id)] += lazy[X][id];
    }
    lazy[X][id] = 0;
}
void modify(int id, int l, int r, const int a, const int b, const int X, const int add){
    push_down(id, l, r, X);
    if(r < a || l > b){
        return;
    }else if(a <= l && r <= b){
        lazy[X][id] += add;
        push_down(id, l, r, X);
        return;
    }
    int Mid = (l + r) >> 1;
    modify(LCN(id), l, Mid, a, b, X, add);
    modify(RCN(id), Mid + 1, r, a, b, X, add);
    seg[X][id] = seg[X][LCN(id)] + seg[X][RCN(id)];
    return;
}
ll query(int id, int l, int r, const int a, const int b, const int X){
    push_down(id, l, r, X);
    if(r < a || l > b){
        return 0;
    }else if(a <= l && r <= b){
        return seg[X][id];
    }
    int Mid = (l + r) >> 1;
    return query(LCN(id), l, Mid, a, b, X) + query(RCN(id), Mid + 1, r, a, b, X);
}
int t, n, m;
int op, l, r, x;
vector<int> fac[MAX_X];
int idtoP[MAX_X], Pid, Ptoid[MAX_X];
bool isnt_prime[MAX_X];
void Modi(int l, int r, int x, bool m){
    for(auto vi : fac[x]){
        int tmp = x, cnt = 0;
        while(tmp % vi == 0){
            cnt++;
            tmp /= vi;
        }
        modify(1, 1, n, l, r, Ptoid[vi], (m ? 1 : -1) * cnt);
    }
}
void Query(ll &ans, int l, int r, int x){
    rep(i, 0, Pid){
        ans *= qpow(idtoP[i], query(1, 1, n, l, r, i), x);
        ans %= x;
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i = 2; i < MAX_X; i++){
        if(!isnt_prime[i]){
            idtoP[Pid] = i;
            Ptoid[i] = Pid++;
            for(int j = i; j < MAX_X; j += i){
                fac[j].push_back(i);
                isnt_prime[j] = true;
            }
        }
    }
    // for(int i = 1; i < MAX_X; i++){
    //     cout << i << ':';
    //     for(auto j : fac[i]){
    //         cout << j << ' ';
    //     }
    //     cout << endl;
    // }

    cin >> t;
    while(t--){
        cin >> n >> m;
        Init(1, 1, n);
        rep(i, 0, m){
            cin >> op >> l >> r >> x;
            if(op == 0){
                ll ans = 1;
                if(l <= r){
                    Query(ans, l, r, x);
                }else{
                    Query(ans, 1, r, x);
                    Query(ans, l, n, x);
                }
                cout << ans << '\n' << flush;
            }else if(op == 1){
                if(l <= r){
                    Modi(l, r, x, true);
                }else{
                    Modi(1, r, x, true);
                    Modi(l, n, x, true);
                }
            }else{
                if(l <= r){
                    Modi(l, r, x, false);
                }else{
                    Modi(1, r, x, false);
                    Modi(l, n, x, false);
                }
            }
        }
    }
    
    return 0;
}
/*
2
6 5
0 1 5 1000000007
1 2 4 15
0 1 6 8704173
2 2 3 3
0 1 6 1000000007
6 6
1 1 4 20
1 2 6 15
0 1 6 9704331
2 3 6 5
0 1 4 1000000007
0 1 5 1000000007
*/
/*
1
6 6

1 4 1 20
1 5 3 15
0 1 6 9704331
2 6 3 5
0 4 1 1000000007
0 4 2 1000000007
*/