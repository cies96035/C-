#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 1e5 + 5;
int DSU[MAX_N];
int n, m;
int a, b;

int Find(int x){
    return DSU[x] < 0 ? x : DSU[x] = Find(DSU[x]);
}
void Union(int x, int y){
    if(Find(x) != Find(y)){
        DSU[Find(y)] = Find(x);
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    
    memset(DSU, -1, sizeof(int) * (n + 1));

    rep(i, 0, m){
        cin >> a >> b;
        Union(a, b);
    }

    vector<pll> ans;
    rep(i, 1, n){
        if(Find(i) != Find(i + 1)){
            ans.push_back({i, i + 1});
            Union(i, i + 1);
        }
    }
    
    cout << ans.size() << '\n';
    for(auto i : ans){
        cout << i.first << ' ' << i.second << '\n';
    }

    return 0;
}