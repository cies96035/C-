#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX = 31663;
// const int MAX = 1e6;
bool isntPrime[MAX];
vector<int> primes;
void g(){
    for(ll i = 2; i < MAX; i++){
        if(!isntPrime[i]){
            for(ll j = i * i; j < MAX; j += i){
                isntPrime[j] = true;
            }
            primes.push_back(i);
        }
    }
    // cout << primes.size() << endl;
}
vector<pair<int, int>> pf;
vector<int> factors;
void dfs(int idx, int val, int cnt){
    if(val > MAX) return;
    if(idx == pf.size()){
        factors.push_back(val);
        return;
    }
    if(cnt != pf[idx].second){
        dfs(idx, val * pf[idx].first, cnt + 1);
    }
    dfs(idx + 1, val, 0);
}
    ll n;
void f(){
    pf.clear();
    factors.clear();
    ll d = n;
    cin >> n;
    for(auto p:primes){
        if(n < p) break;
        if(n % p == 0){
            pf.push_back({p, 1});
            n /= p;
            while(n % p == 0){
                pf.back().second++;
                n /= p;
            }
        }
    }
    dfs(0, 1, 0);
    sort(factors.begin(), factors.end());
    int cnt = 1, ans = 1;
    rep(i, 1, factors.size()){
        if(factors[i] - factors[i - 1] == 1){
            cnt++;
            ans = max(cnt, ans);
        }else{
            cnt = 1;
        }
    }
    cout << ans << '\n';
    return;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    g();
    int t;
    cin >> t;
    while(t--){
        f();
    }
    return 0;
}