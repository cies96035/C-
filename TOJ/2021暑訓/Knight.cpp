#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 55;
const int INF = 0x3fffffff;

int t, n, board[MAX_N][MAX_N], id = 1, x, y;
int *idcnt = new int[5100] + 2550;
bool flg = false;
queue<tuple<int, int, int>> BFS;
void DFS(int i, int j, bool sign){
    BFS.push({i, j, sign});
    while(!BFS.empty()){
        int x, y, z;
        tie(x, y, z) = BFS.front();
        BFS.pop();
        if(x < 0 || y < 0 || x >= n || y >= n){
            continue;
        }else if(board[x][y] != 0){
            continue;
        }
        board[x][y] = (z ? 1 : -1) * id;
        idcnt[(z ? 1 : -1) * id]++;
        BFS.push({x - 2, y - 1, !z});
        BFS.push({x - 1, y - 2, !z});
        BFS.push({x + 2, y - 1, !z});
        BFS.push({x + 1, y - 2, !z});
        BFS.push({x - 2, y + 1, !z});
        BFS.push({x - 1, y + 2, !z});
        BFS.push({x + 2, y + 1, !z});
        BFS.push({x + 1, y + 2, !z});
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> t;
    rep(i, -2500, 2500){
        idcnt[i] = 0;
    }
    rep(i, 0, n){
        rep(j, 0, n){
            board[i][j] = 0;
        }
    }

    rep(i, 0, t){
        cin >> x >> y;
        board[x][y] = INF;
    }

    rep(i, 0, n){
        rep(j, 0, n){
            if(board[i][j] == 0){
                DFS(i, j, true);
                id++;
            }
        }
    }

    // rep(i, 0, n){
    //     rep(j, 0, n){
    //         cout << setw(3);
    //         if(board[i][j] == INF){
    //             cout << '*';
    //         }else{
    //             cout << board[i][j];
    //         }
                
    //     }
    //     cout << endl;
    // }
    int sum = 0;
    rep(i, 1, id){
        sum += max(idcnt[i], idcnt[-i]);
    }
    cout << sum << '\n';
    return 0;
}