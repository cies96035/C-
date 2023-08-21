#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 3e5 + 5;
pll p[MAX_N];
int ans;
void f(){
    int n;
    cin >> n;
    int ipt;
    rep(i, 0, n){
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p, p + n);
    ll Min1 = n;
    ll Min2 = n;
    ans = 0;
    rep(i, 0, n){
        // cout << p[i].second << endl;
        if(i == 0 || (p[i].second < Min1 || Min2 < p[i].second)){ // loss
            Min1 = min(Min1, p[i].second);
        }else{ // win
            Min2 = min(p[i].second, Min2);
            ans++;
        }
        // cout << Min1 << ' ' << Min2 << endl;
    }
    cout << ans << '\n';
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