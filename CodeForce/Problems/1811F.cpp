#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 5;
int n, m;
struct{
    vector<int> e;
    int cnt;
}nodes[MAX_N];

bool dfs(int cur, int par, int s, int Size = 2){
    // cout << cur << ' ' << par << ' ' << s << endl;
    nodes[s].cnt++;
    if(cur == s){
        return true;
    }else if(nodes[cur].e.size() != Size){
        return false;
    }
    if(Size == 4){
        for(auto nx: nodes[cur].e){
            if(nodes[nx].e.size() == 4 && nx != par){
                return dfs(nx, cur, s, 4);
            }
        }
    }
    for(auto nx: nodes[cur].e){
        if(nx != par){
            return dfs(nx, cur, s);
        }
    }
}

bool check(){
    int k = round(sqrt(n));
    if(k * k == n){
    }else if((k + 1) * (k + 1) == n){
        k = k + 1;
    }else if((k - 1) * (k - 1) == n){
        k = k - 1;
    }else{
        return false;
    }
    int cntDeg4 = 0;
    bool flg = true;
    rrep(i, 1, n){
        if(nodes[i].e.size() == 4){
            cntDeg4++;
            int cnt[2] = {0};
            int nx[2];
            for(auto nei: nodes[i].e){
                if(nodes[nei].e.size() == 4){
                    cnt[0]++;
                    nx[1] = nei;
                }else if(nodes[nei].e.size() == 2){
                    cnt[1]++;
                    nx[0] = nei;
                }
            }
            if(cnt[0] != 2 || cnt[1] != 2){
                // cerr << 'b' << endl;
                return false;
            }
            if(!dfs(nx[0], i, i) || nodes[i].cnt != k){
                // cerr << 'c' << endl;
                return false;
            }
            if(flg){
                if(!dfs(nx[1], i, i, 4) || nodes[i].cnt != 2 * k){
                    return false;
                }
                flg = false;
            }
        }else if(nodes[i].e.size() != 2){
            // cerr << 'd' << endl;
            return false;
        }
    }
    return cntDeg4 == k;
}
void f(){
    cin >> n >> m;
    rrep(i, 1, n){
        nodes[i].cnt = 0;
        nodes[i].e.clear();
    }
    int u, v;
    rep(i, 0, m){
        cin >> u >> v;
        nodes[u].e.push_back(v);
        nodes[v].e.push_back(u);
    }
    if(check()){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }

}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while(t--) f();
    
    return 0;
}