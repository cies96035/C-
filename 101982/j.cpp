#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

int n, s;
ll t[3000];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ll Max = -1e9;
    cin >> n >> s;
    rep(i, 0, n){
        cin >> t[i];
        Max = max(t[i], Max);
    }
    Max *= s;
    cout << (Max + 999) / 1000 << endl;
    return 0;
}