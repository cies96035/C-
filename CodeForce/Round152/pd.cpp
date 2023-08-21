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
    cin >> n;
    vector<int> as;
    int a;
    rep(i, 0, n){
        cin >> a;
        if(a == 0) as.push_back(a);
        if(a == 1){
            if(as.empty() || as.back() == 0) as.push_back(a);
        }
        if(a == 2){
            if(as.empty() || as.back() == 0) as.push_back(a);
            else if(as.back() == 1) as.back() = 2;
        }
    }
    ll ans = 0;
    rep(i, 0, as.size()){
        if(i < as.size() - 1 && as[i] == 0 && as[i + 1] == 2){
            i += 2;
        }else if(i < as.size() - 1 && as[i] + as[i + 1] >= 1){
            i++;
        }
        ans++;
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