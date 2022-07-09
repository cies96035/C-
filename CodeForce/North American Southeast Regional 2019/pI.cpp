#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_RC = 1010;
int r, c;
char naze[MAX_RC][MAX_RC];
char maze[MAX_RC * 2][MAX_RC * 2];
int cnt;
void DFS(int curx, int cury){
    if(curx < 0 || cury < 0 || curx == r || cury == c){ // outbound
        return;
    }else if(maze[curx][cury] == '*'){
        return;
    }
    maze[curx][cury] = '*';
    DFS(curx, cury + 1);
    DFS(curx + 1, cury);
    DFS(curx, cury - 1);
    DFS(curx - 1, cury);
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> r >> c;
    rep(i, 0, r){
        rep(j, 0, c){
            cin >> naze[i][j];
            if(naze[i][j] == '/'){
                maze[i * 2 + 1][j * 2 + 1] = '.';
                maze[i * 2 + 1][j * 2 + 2] = '*';
                maze[i * 2 + 2][j * 2 + 1] = '*';
                maze[i * 2 + 2][j * 2 + 2] = '.';
            }else if(naze[i][j] == '\\'){
                maze[i * 2 + 1][j * 2 + 1] = '*';
                maze[i * 2 + 1][j * 2 + 2] = '.';
                maze[i * 2 + 2][j * 2 + 1] = '.';
                maze[i * 2 + 2][j * 2 + 2] = '*';
            }else{
                maze[i * 2 + 1][j * 2 + 1] = '.';
                maze[i * 2 + 1][j * 2 + 2] = '.';
                maze[i * 2 + 2][j * 2 + 1] = '.';
                maze[i * 2 + 2][j * 2 + 2] = '.';
            }
        }
    }
    r <<= 1;
    c <<= 1;
    r += 2;
    c += 2;
    rep(i, 0, r){
        maze[i][0] = '.';
        maze[i][c - 1] = '.';
    }
    rep(i, 0, c){
        maze[0][i] = '.';
        maze[r - 1][i] = '.';
    }
    // cout << r << c << endl;
    rep(i, 0, r){
        rep(j, 0, c){
            // cout << maze[i][j];
            if(maze[i][j] == '.'){
                DFS(i, j);
                cnt++;
            }
        }
        // cout << endl;
    }
    cout << cnt - 1 << '\n';

    return 0;
}