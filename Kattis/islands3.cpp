#include<iostream>
using namespace std;

const int MAX_RC = 60;
char grid[MAX_RC][MAX_RC];
int R, C;
int cnt;

void DFS(int x, int y){
    if(x < 0 || y < 0 || x >= R || y >= C){
        return;
    }else if(grid[x][y] == 'W'){
        return;
    }
    
    grid[x][y] = 'W';

    DFS(x - 1, y);
    DFS(x + 1, y);
    DFS(x, y - 1);
    DFS(x, y + 1);
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> grid[i][j];
        }
    }
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(grid[i][j] == 'L'){
                DFS(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}