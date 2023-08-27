#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 5;
ll a[MAX_N];
void Remove(map<ll, ll> &m, ll x){
    m[x]--;
    if(m[x] == 0){
        m.erase(x);
    }
}
void f(){
    ll n;
    cin >> n;
    map<ll, ll> cnt, d;
    rrep(i, 1, n){
        cin >> a[i];
        cnt[a[i]]++;
    }
    ll lasted = -1;
    for(auto i :cnt){
        if(lasted != -1){
            d[i.first - lasted]++;
        }
        lasted = i.first;
    }
    d[0] = 0;
    ll q, x, y;
    cin >> q;
    while(q--){
        cin >> x >> y;
        if(cnt[a[x]] == 1){
            auto tmp = cnt.find(a[x]);
            if(tmp != cnt.begin()){
                --tmp;
                Remove(d, a[x] - tmp->first);
                ++tmp;
            }
            if(++tmp != cnt.end()){
                Remove(d, tmp->first - a[x]);
            }
            --tmp;
            if(tmp != cnt.begin() && tmp != --cnt.end()){
                auto tmp2 = tmp; 
                tmp--, tmp2++;
                d[tmp2->first - tmp->first]++;
            }
        }

        Remove(cnt, a[x]);
        a[x] = y;
        cnt[y]++;

        if(cnt[y] == 1){
            auto tmp = cnt.find(y);
            if(tmp != cnt.begin() && tmp != --cnt.end()){
                auto tmp2 = tmp;
                tmp--, tmp2++;
                Remove(d, tmp2->first - tmp->first);
            }
            tmp = cnt.find(y);
            if(tmp != cnt.begin()){
                tmp--;
                d[y - tmp->first]++;
                tmp++;
            }
            if(++tmp != cnt.end()){
                d[tmp->first - y]++;
            }
        }
        // cout << "CNT\n";
        // for(auto j:cnt){
        //     cout << j.first << ' ';
        // }cout << '\n';
        // cout << "d\n";
        // for(auto j:d){
        //     cout << j.first << ' ';
        // }cout << '\n';
        cout << cnt.rbegin()->first + d.rbegin()->first << ' ';
        // cout << '\n';
    }
    // cout <<
    cout << '\n';
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