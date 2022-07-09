#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)
#define x first
#define y second
#define int ll
#define pb emplace_back
#define all(x) x.begin(), x.end()

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

const int INF = 3e17 + 5;
const int MAX_N = 1e5 + 5;

map<int, int> ps, now;
set <int> ss;

int f(int t, int p, int &s) {
    auto it = ss.lower_bound(p);
    if (it == ss.begin())
        it = prev(ss.end());
    else
        --it;
    
    int len = (p - *it + s) % s;
    return len * (t + t + len - 1) / 2;
}

void g(int a, int b) {
    int g = __gcd(a, b);
    a /= g, b /= g;
    cout << a << '/' << b << endl;
}

signed main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, s, t;
    cin >> n >> s >> t;
    int k;
    rep(i, 0, n)
        cin >> k, ++ps[k], ss.insert(k);

    ll m = INF, M = -INF, sum = 0;
    for (auto &p : ss) {
        now = ps;
        cout << now.size() << endl;
        cout << ps.size() << endl;
        int st = p;
        int T = 0;
        for (int i = 0; i < n; ++i) {
            auto nxt = now.lower_bound(st);
            if (nxt == now.end())
                nxt = now.begin();

            T += (nxt->x - st + s) % s + t;
            st = nxt->x;

            --nxt->y;
            if (!nxt->y) now.erase(nxt);
            // cout << T << endl;
        }
        // cout << p << endl;
        // cout << T << endl;
        m = min(m, T);
        M = max(M, T);
        sum += f(T, p, s);
    }
    // m += n * t;
    // M += n * t;
    // sum += n * t * s;
    cout << m << endl << M << endl;
    g(sum, s);
    return 0;
}