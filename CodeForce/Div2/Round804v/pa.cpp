#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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
        cin >> n;
        if(n & 1){
            cout << "-1\n";
        }else{
            cout << "0 0 " << n / 2 << '\n';
        }
    }
    return 0;
}