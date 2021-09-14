#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 5e3 + 5;
int n, x;
pll a[MAX_N];

pll sumOfTwo(pll *s, pll* e, int x){
    while(s != e){
        if(s->first + e->first < x){
            s++;
        }else if(s->first + e->first > x){
            e--;
        }else{
            return {s->second, e->second};
        }
    }
    return {-1, -1};
}
void solve(){
    rep(i, 2, n){
        auto tmp = sumOfTwo(a, a + i - 1, x - a[i].first);
        if(tmp != pll{-1, -1}){
            cout << tmp.first << ' ' << tmp.second << ' ' << a[i].second << '\n';
            return;
        }
    }
    cout << "IMPOSSIBLE\n";
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> x;
    rep(i, 0, n){
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a, a + n);
    solve();
    return 0;
}