#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

int a[3];
int t;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        cout << a[1] << endl;
    }
    return 0;
}