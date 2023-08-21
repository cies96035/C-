#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)
void f(){
    int n;
    priority_queue<int> pq;
    cin >> n;
    int s;
    ll ans = 0;
    rep(i, 0, n){
        cin >> s;
        if(s == 0 && !pq.empty()){
            ans += pq.top();
            pq.pop();
        }else{
            pq.push(s);
        }
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