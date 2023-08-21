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
    vector<int> a = {5, 2, 3, 1, 4};
    vector<int> b = {3, 1, 4, 2, 5};
    
    map<int, int> posOfB;
    rep(i, 0, 5){
        posOfB[b[i]] = i;
    }
    rep(i, 0, 5){
        int pos = posOfB[a[i]];
        swap(b[i], b[pos]);
        swap(posOfB[ b[i] ], posOfB[ b[pos] ]);
    }
    rep(i, 0, 5) cout << b[i] << " \n"[i == 4];
    return 0;
}