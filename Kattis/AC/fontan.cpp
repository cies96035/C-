#include<bits/stdc++.h>
using namespace std;

const int MAX_NM = 55;

char Map[MAX_NM][MAX_NM];
bool used[MAX_NM][MAX_NM];
int n, m;
void DFS(int x, int y){
    if(Map[x][y] == '#' || used[x][y] || x < 0 || x >= n || y < 0 || y >= m){
        return;
    }
    used[x][y] = true;
    Map[x][y] = 'V';
    if(Map[x + 1][y] == '#'){
        DFS(x, y - 1);
        DFS(x, y + 1);
    }else{
        DFS(x + 1, y);
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> Map[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(Map[i][j] == 'V' && !used[i][j]){
                DFS(i, j);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << Map[i][j];
        }
        cout << '\n';
    }
    return 0;
}