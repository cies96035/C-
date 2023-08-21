#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 1e2 + 5;
int ring[MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        set<int> s;
        rep(i, 0, n){
            cin >> ring[i];
            s.insert(ring[i]);
        }
        if(s.size() == 2){
            cout << n / 2 + 1 << '\n';
        }else{
            cout << n << '\n';
        }
    }
    return 0;
}
