#include<bits/stdc++.h>
using namespace std;

#define int ll
#define IOS ios::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define f0r(i, a) for (int i = 0; i < a; ++i)
#define pb emplace_back
#define x first
#define y second

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int V = 1000000;

int inv[V];
int c[V];
vi o, n;

void solve() {
    int p;
    cin >> p;

    inv[1] = 1;
    for (int i = 2; i < p; ++i)
        inv[i] = (p - (p / i) * inv[p % i] % p) % p;
    
    int x;
    for (int i = 1; i < p; ++i)
        cin >> x, ++c[x % p];

    if (c[1]) return cout << "Yes\n", void();

    
}


signed main () {
    IOS;
    int n = 1;
    // cin >> n;
    while (n--)
        solve();
}
