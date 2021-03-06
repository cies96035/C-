#include<iostream>
using namespace std;

const int MAX = 1010;

int R, C;
int r1, c1, r2, c2;
int visid = 0;
int n;
char c;
int Map[MAX][MAX];
bool isConnect;
int Id = 0;
bool type;
void DFS(int x, int y){
    if( x < 0 || y < 0 || x >= R || y >= C || Map[x][y] != type){
        return;
    }

    if(type){
        Map[x][y] = Id + 1;
    }else{
        Map[x][y] = Id;
    }
    
    DFS(x - 1, y);
    DFS(x + 1, y);
    DFS(x, y - 1);
    DFS(x, y + 1);
    return;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> c;
            Map[i][j] = c - '0';
        }
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(Map[i][j] > 1){
                continue;
            }
            type = Map[i][j];
            Id += 2;
            DFS(i, j);
        }
    }
    
    cin >> n;
    while(n--){
        cin >> r1 >> c1;
        cin >> r2 >> c2;
        r1--; r2--;
        c1--; c2--;
        if(Map[r1][c1] == Map[r2][c2]){
            if(Map[r1][c1] % 2){
                cout << "decimal\n";
            }else{
                cout << "binary\n";
            }
        }else{
            cout << "neither\n";
        }
    }
    return 0;
}