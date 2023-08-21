#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 5;
const int MOD = 998244353;
pll dsu[MAX_N];
ll ans[MAX_N];
ll quickPower(ll a, ll b, ll mod){
    ll ans = 1;
    while(b){
        if(b % 2){
            ans *= a;
            ans %= mod;
        }
        b >>= 1;
        a *= a;
        a %= mod;
    }
    return ans;
}
void Init(int n){ rrep(i, 1, n) dsu[i] = {i, 1}, ans[i] = 1; }
int Find(int x){ 
    return dsu[x].first == x ? dsu[x].first : dsu[x].first = Find(dsu[x].first); 
}
void Union(ll a, ll b, ll v){ 
    a = Find(a);
    b = Find(b);
    if(dsu[a].second < dsu[b].second) swap(a, b);
    ll E = (dsu[b].second * dsu[a].second - 1);
    if(E > 0){
        ll tmp = quickPower(v + 1, E, MOD);
        ans[a] = ans[b] * ans[a] % MOD * tmp % MOD;
    }
    // if(E > 0){
    //     ans += quickPower(2, E, MOD) * v % MOD;
    //     ans %= MOD;
    // }
    // cout << v << endl;
    // cout << a << ' ' << ans[a] << ' ' << dsu[a].second << '\n';
    // cout << b << ' ' << ans[b] << ' ' << dsu[b].second << '\n';
    // cout << ans[a] << '\n';
    dsu[b].first = dsu[a].first; 
    dsu[a].second += dsu[b].second;
}
bool Same(int a, int b){ return Find(a) == Find(b); }
struct EDGE{
    ll u, v, w;
    bool operator<(const EDGE &y){
        return w != y.w ? w < y.w :
        u != y.u ? u < y.u : 
        v < y.v;
    }
}e[MAX_N];
void f(){
    int n, S;
    cin >> n >> S;
    Init(n);
    rep(i, 0, n - 1){
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e, e + n - 1);
    rep(i, 0, n - 1){
        Union(e[i].u, e[i].v, S - e[i].w);
    }
    cout << ans[Find(1)] << '\n';
    // cout << flush;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while(t--) f();
    
    return 0;
}