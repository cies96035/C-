#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 5;
const int MAX_M = 1e5 + 5;
int n, m;
int b[MAX_N], a[MAX_N];
pll edge[MAX_M];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    rep(i, 0, m){
        cin >> edge[i].first >> edge[i].second;
    }
    sort(edge, edge + m);
    rrep(i, 1, n){
        a[i] = 1;
    }
    rep(i, 0, m){
        a[ edge[i].second ] = a[ edge[i].second + 1 ] = b[ edge[i].second ] = 
        a[ edge[i].second ] + a[ edge[i].second + 1 ] - b[ edge[i].second ];
    }
    rrep(i, 1, n){
        cout << a[i] << ' ';
    }cout << endl;
    return 0;
}