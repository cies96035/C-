#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t, n;
    cin >> t;
    while(t--){
        int a, b;
        set<pll> s;
        cin >> n;
        rrep(i, 1, n){
            cin >> a >> b;
            if(a <= 10){
                s.insert({b, i});
            }
        }
        // for(auto i : s){
        //     cout << i.first << ' ' << i.second << endl;
        // }
        cout << s.rbegin()->second << '\n';
    }
    return 0;
}