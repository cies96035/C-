#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 1005;
int n, m, cnt;
char c[MAX_N][MAX_N];
void DFS(int x, int y){
    if(x < 0 || y < 0 || 
    x >= n || y >= m || c[x][y] == '#'){
        return;
    }
    c[x][y] = '#';
    DFS(x - 1, y);
    DFS(x + 1, y);
    DFS(x, y - 1);
    DFS(x, y + 1);
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    rep(i, 0, n){
        rep(j, 0, m){
            cin >> c[i][j];
        }
    }
    rep(i, 0, n){
        rep(j, 0, m){
            if(c[i][j] == '.'){
                DFS(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}