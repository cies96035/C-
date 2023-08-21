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

    int t, a[3];
    cin >> t;
    while(t--){
        rep(i, 0, 3){
            cin >> a[i];
        }
        sort(a, a + 3);
        if(a[1] + a[2] >= 10){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}