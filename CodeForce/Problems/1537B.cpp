#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll len(ll x1, ll y1, ll x2, ll y2){
    return abs(x1 - x2) + abs(y1 - y2);
}
inline ll looplen(int x1, int y1, int x2, int y2, int x3, int y3){
    return 
    len(x1, y1, x2, y2) +
    len(x1, y1, x3, y3) +
    len(x2, y2, x3, y3);
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t;
    int n, m, i, j;
    cin >> t;
    while(t--){
        cin >> n >> m >> i >> j;
        if(looplen(1, 1, n, m, i, j) < looplen(1, m, n, 1, i, j) ){
            cout << 1 << ' ' << 1 << ' ' << n << ' ' << m << '\n';
        }else{
            cout << 1 << ' ' << m << ' ' << n << ' ' << 1 << '\n';
        }
    }
    return 0;
}