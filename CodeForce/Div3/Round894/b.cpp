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
    int b;
    vector<int> ans;
    rep(i, 0, n){
        cin >> b;
        if(i > 0){
            if(b != 1){
                ans.push_back(1);
            }
        }
        if(i != 0 || b != 1){
            ans.push_back(b);
        }
    }
    if(b == 1) ans.push_back(1);
    cout << ans.size() << '\n';    
    for(auto i : ans){
        cout << i << ' ';
    }
    cout << '\n';
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