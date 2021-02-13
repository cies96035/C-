#include<iostream>
#include<climits>
using namespace std;

const int MAX_XY = 550;
int table[MAX_XY][MAX_XY];
bool vis[MAX_XY][MAX_XY];
int x, y;

bool isMin;
int cnt;
int sum;

void dfs(int x, int y, int N){
    if(table[x][y] < N){
        isMin = 0;
        return;
    }else if(table[x][y] > N){
        return;
    }else if(vis[x][y] == 1)
        return;

    cnt++;
    vis[x][y] = 1;
    dfs(x - 1, y, N);
    dfs(x + 1, y, N);
    dfs(x, y - 1, N);
    dfs(x, y + 1, N);
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> y >> x;
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y ;j++){
            cin >> table[i][j];
        }
    }

    for(int i = 1; i <= y ;i++){
        table[0][i] = table[x + 1][i] = INT_MAX;
    }

    for(int i = 1; i <= x; i++){
        table[i][0] = table[i][y + 1] = INT_MAX;
    }

    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y; j++){
            cnt = 0;
            isMin = 1;
            dfs(i, j, table[i][j]);
            if(isMin){
                sum += cnt;
            }
        }
    }

    cout << sum << '\n';
    return 0;
}