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
    
    int t;
    cin >> t;
    while(t--){
        int n, m, x, y, d;
        cin >> n >> m >> x >> y >> d;
        if(x - d <= 1 && x + d >= n || y - d <= 1 && y + d >= m ||
        x - d <= 1 && y - d <= 1 || x + d >= n && y + d >= m) cout << "-1\n";
        else cout << n + m - 2 << '\n';
    }
    return 0;
}