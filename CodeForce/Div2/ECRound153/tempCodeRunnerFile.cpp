#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_S = 5e4 + 5;
vector<int> e[26 * 26];
string str;
int dis[26 * 26][MAX_S];
int vis[MAX_S], visId = 0;
int vis2[26 * 26];

inline int charToInt(char a, char b){
    return (a - 'a') * 26 + b - 'a';
}

inline void Link(int a, int b){
    e[a].push_back(b);
}

inline void BFS(int f){
    visId++;
    queue<pll> q;
    vis2[f] = visId;
    for(auto &nx:e[f]){
        q.push({1, nx});
        vis[nx] = visId;
    }
    int cnt = 0;
    while(!q.empty()){
        cnt ++;
        int dep = q.front().first;
        int cur = q.front().second;
        q.pop();
        dis[f][cur] = dep;
        if(cur < str.size() - 1){
            int nx = charToInt(str[cur], str[cur + 1]);
            if(vis2[nx] != visId){
                for(auto &nxx:e[nx]){
                    if(vis[nxx] != visId){
                        q.push({dep + 1, nxx});
                        vis[nxx] = visId;
                    }
                }
                vis2[nx] = visId;
            }
        }
        if(cur < str.size() - 1 && vis[cur + 1] != visId){
            q.push({dep + 1, cur + 1});
            vis[cur + 1] = visId;
        }
        if(cur > 0 && vis[cur - 1] != visId){
            q.push({dep + 1, cur - 1});
            vis[cur - 1] = visId;
        }
        // if(q.size()>str.size())
        // cout << q.size() << endl;
    }
    // cout << cnt << endl;
}
void f(){
    cin >> str;
    // rep(i, 0, 50000) str += rand() % 26 + 'a';
    rep(i, 0, str.size() - 1){
        int tmp = charToInt(str[i], str[i + 1]);
        Link(tmp, i);
    }
    int q, f, t;
    rep(i, 0, 676){
        BFS(i);
        // cout << i<< endl;
        // cout << char(i / 26 + 'a') << ' ' << char(i % 26 + 'a') << ' ';
        // rep(j, 0, str.size()){
        //     cout << dis[i][j] << ' ' ;
        // }cout << endl;
    }
    cin >> q;
    int ans;
    rep(i, 0, q){