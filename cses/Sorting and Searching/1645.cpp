#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

stack<pll> si;
int n, x;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    si.push({0, 0});
    rep(i, 0, n){
        cin >> x;
        while(si.top().first >= x){
            si.pop();
        }
        cout << si.top().second << ' ';
        si.push({x, i + 1});
    }cout << '\n';

    return 0;
}