#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 5;
int t;
int n;
int a[MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        rep(i, 0, n){
            cin >> a[i];
        }
        char c;
        vector<int> r, b;
        rep(i, 0, n){
            cin >> c;
            if(c == 'R'){
                r.push_back(a[i]);
            }else{
                b.push_back(a[i]);
            }
        }
        sort(r.begin(), r.end());
        vector<bool> ok(false, n);
        rep(i, 0, r.size()){
            if()
        }

        }
    }
    return 0;
}