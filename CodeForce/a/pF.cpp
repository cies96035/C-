#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define X first
#define Y second

using pii = pair<int, int>;
using vi = vector<int>;

using Edge = pii;

const int V = 2005;
const int E = 200005;
const int INF = 1000000000000;

bool vis[V];
int d[V];
vector <pii> g[V];
vector <int> r[V];

int in[V];
vi dag[V];

int ans[V];

priority_queue<int, vector<int>, greater<int> > pql;

void dfs(int x) {
    vis[x] = 1;
    for (int y : r[x])
        ++in[x], dag[y].pb(x), dfs(y);
}

bool O(const int& a, const int &b) {
    return d[a] < d[b];
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, X, Y;
    cin >> N >> X >> Y;

    int m;
    cin >> m;

    int x, y, l;
    while (m--) {
        cin >> x >> y >> l;
        g[x].pb(Edge(y, l));
        g[y].pb(Edge(x, l));
    }

    for (int i = 1; i <= N; ++i)
        d[i] = INF;

    priority_queue<pii> pq;
    pq.push(pii(0, X));
    d[X] = 0;

    while (!pq.empty()) {
        int i = pq.top().Y; pq.pop();

        if (vis[i]) continue;
        vis[i] = 1;

        for (Edge &e: g[i]) {
            int &j = e.X;
            int w = e.Y + d[i];
            if (w < d[j]) {
                d[j] = w;
                pq.push(pii(-d[j], j));
                r[j].clear();
                r[j].pb(i);
            }
            else if (w == d[j]) {
                r[j].pb(i);
            }
        }
    }

    for (int i = 1; i <= N; ++i)
        vis[i] = 0;
    dfs(Y);

    vector<int> v;
    for (int i = 1; i <= N; ++i)
        v.pb(i);
    
    sort(all(v), O);

    // multiset<int> ms;
    int td = -1;
    vi tr;
    
    // v.pb(0);
    for (int &i : v) {
        if (!vis[i]) continue;
        // cout << i << endl;
        // cout << pql.size() << endl;
        if (d[i] != td) {
            for (int &y : tr) {
                ans[y] += tr.size();
                for (int &z : dag[y])
                    pql.push(d[z]);
                    // ms.insert(z);
            }
            tr.clear();
            td = d[i];
        }
        while (!pql.empty() && pql.top() <= d[i])
            pql.pop();
        // ans[i] = ms.upper_bound(d[i]);
        ans[i] = pql.size();
        tr.pb(i);
    }
    for (int &y : tr) {
        ans[y] += tr.size();
        for (int &z : dag[y])
            // ms.insert(z);
            pql.push(d[z]);
    }

    for (int i = 1; i <= N; ++i)
        cout << ans[i] << ' ';
    cout << endl;
}
/*
6 2 5 9
1 2 1 1 3 10
1 6 1 4 6 1
6 5 1 2 6 2
3 6 1 5 3 1
4 5 1
*/