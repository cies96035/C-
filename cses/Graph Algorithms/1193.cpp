#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)
#define X first
#define Y second

const int MAX_NM = 1e3 + 5;
const pll mv[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int n, m;
char G[MAX_NM][MAX_NM];
pll par[MAX_NM][MAX_NM];
pll apos, bpos;

inline bool outbound(pll cur){
    return (cur.X < 0 || cur.X >= n || cur.Y < 0 || cur.Y >= m);
}

bool BFS(pll x){
    queue<pll> bfs;
    bfs.push(x);
    G[x.X][x.Y] = '#';
    while(!bfs.empty()){
        pll cur = bfs.front();
        bfs.pop();

        for(auto i : mv){
            pll nx = {cur.X + i.X, cur.Y + i.Y};
            if(!outbound(nx)){
                if(G[nx.X][nx.Y] == 'B'){
                    par[nx.X][nx.Y] = cur;
                    return true;
                }else if(G[nx.X][nx.Y] != '#'){
                    par[nx.X][nx.Y] = cur;
                    bfs.push({nx.X, nx.Y});
                }
                G[nx.X][nx.Y] = '#';
            }
        }
    }
    return false;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    rep(i, 0, n){
        rep(j, 0, m){
            cin >> G[i][j];
            if(G[i][j] == 'A'){
                apos = {i, j};
            }
            if(G[i][j] == 'B'){
                bpos = {i, j};
            }
        }
    }
    if(BFS(apos)){
        cout << "YES\n";
        string path;
        while(bpos != apos){
            if(par[bpos.X][bpos.Y].X < bpos.X) path += 'D';
            else if(par[bpos.X][bpos.Y].X > bpos.X) path += 'U';
            else if(par[bpos.X][bpos.Y].Y < bpos.Y) path += 'R';
            else if(par[bpos.X][bpos.Y].Y > bpos.Y) path += 'L';
            bpos = par[bpos.X][bpos.Y];
        }
        reverse(path.begin(), path.end());
        cout << path.size() << '\n' << path << '\n';
    }else{
        cout << "NO\n";
    }
    return 0;
}