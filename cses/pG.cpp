#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 5;
int n;
pll p[MAX_N];
bool cmp(pll a, pll b){
    return a.first + a.second > b.first + b.second;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    n *= 2;
    rep(i, 0, n){
        cin >> p[i].first >> p[i].second;
        if(p[i].first > p[i].second)
            swap(p[i].first, p[i].second);
    }
    sort(p, p + n, cmp);
    n >>= 1;
    ll sum = 0;
    rep(i, 0, n){
        sum += p[i].second;
        sum -= p[n + i].first;
    }
    cout << sum << '\n';
    return 0;
}