#include<iostream>
#include<queue>
using namespace std;

const int MAX_MN = 500;
struct POINT{
    int x;
    int y;
    int depth;
    POINT(int a, int b, int c){
        x = a;
        y = b;
        depth = c;
    }
    POINT(){}
};
int n, m;
bool vised[MAX_MN][MAX_MN];
int grid[MAX_MN][MAX_MN];
char c;
queue<POINT> togo;
int BFS(){
    togo.push(POINT(0, 0, 0));
    POINT tmp;
    int step;
    while(!togo.empty()){
        tmp = togo.front();
        togo.pop();
        if(tmp.x < 0 || tmp.x >= n || tmp.y < 0 || tmp.y >= m){
            continue;
        }else if(vised[tmp.x][tmp.y]){
            continue;
        }else if(tmp.x == n - 1 && tmp.y == m - 1){
            return tmp.depth;
        }
        vised[tmp.x][tmp.y] = true;
        step = grid[tmp.x][tmp.y];
        togo.push( POINT(tmp.x + step, tmp.y, tmp.depth + 1) );
        togo.push( POINT(tmp.x - step, tmp.y, tmp.depth + 1) );
        togo.push( POINT(tmp.x, tmp.y + step, tmp.depth + 1) );
        togo.push( POINT(tmp.x, tmp.y - step, tmp.depth + 1) );
    }
    return -1;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> c;
            grid[i][j] = c - '0';
        }
    }
    cout << BFS() << '\n';
    return 0;
}