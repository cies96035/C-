#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 1e4;
ll t;
ll n, l, r, k;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> n >> l >> r >> k;
        vector<ll> p;
        ll x;
        rep(i, 0, n){
            cin >> x;
            if(l <= x && x <= r){
                p.push_back(x);
            }
        }
        sort(p.begin(), p.end());
        int cnt = 0;
        for(auto q : p){
            if(k >= q){
                k -= q;
                cnt++;
            }else{
                break;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}