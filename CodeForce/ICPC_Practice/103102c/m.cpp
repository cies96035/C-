#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 5e5 + 5;
vector<int> d[MAX_N], pos[MAX_N];
int ans[MAX_N];
// void DFS(int x){
//     if(d[x].empty()){
        
//     }
// }
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n, k, m, a, b;
    cin >> n >> k >> m;
    rep(i, 0, m){
        cin >> a >> b;
        d[b].push_back(a);
    }
    int tmp = k * n;
    rep(i, 0, tmp){
        cin >> a;
        pos[a].push_back(i);
        cout << pos[a].size() << ' ';
    }
    cout << endl;
    // DFS(1);

    return 0;
}