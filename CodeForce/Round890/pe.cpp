#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 1e6 + 5;
vector<int> e[MAX_N];
int chs[MAX_N];
int n;
ll dfs(int cur, int par){
    chs[cur]++;
    for(auto nx : e[cur]){
        if(nx != par){
            chs[cur] += dfs(nx, cur);
        }
    }
    return chs[cur];
}
template <int len = 1>
ll cnt(int cur){
    ll MAX = 0, sum = chs[cur] - 1;
    ll m = sum / 2;
    if (m >= len) {
        return cnt<min(len * 2, MAX_N)>(cur);
    }
    bitset<len> dp;
    map<int, int> cnt;
    for(auto nx : e[cur]){
        if(chs[nx] >= m){
            return (sum - chs[nx]) * chs[nx];
        }
        cnt[chs[nx]]++;
    }
    dp = 0;
    dp[0] = 1;
    for(auto c: cnt){
        if(c.second > 2){
            cnt[c.first * 2] += (c.second - 1) / 2;
            c.second = 2 - (c.second & 1);
        }
        while(c.second--)
            dp |= dp << c.first;
    }
    rvep(i, m, 0){
        if(dp[i]) return (sum - i) * i;
    }
}
void f(){
    cin >> n;
    int x;
    rrep(i, 2, n){
        cin >> x;
        // x = i - 1;
        e[x].push_back(i);
    }
    dfs(1, 0);
    ll ans = 0;
    rrep(i, 1, n){
        ans += cnt(i);
    }
    cout << ans << '\n';
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while(t--) f();
    
    return 0;
}