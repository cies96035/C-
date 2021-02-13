#include<iostream>
#include<queue>
using namespace std;

const int MAX_N = 150;

char table[MAX_N][MAX_N];
struct Walk{
    int x;
    int y;
    int step;
    Walk(int a, int b, int c){
        x = a;
        y = b;
        step = c;
    }
    Walk(){
        x = y = step = 0;
    }
};

int N, posxK, posyK;

void BFS(int x, int y){

    queue<Walk> togo;
    togo.push( Walk(x, y, 0) );

    while(!togo.empty()){
        Walk tmp = togo.front();
        togo.pop();
        if(tmp.x < 0 || tmp.y < 0 || tmp.x >= N || tmp.y >= N){
            continue;
        }else if(table[tmp.x][tmp.y] == '#'){
            continue;
        }

        if(tmp.x == 0 && tmp.y == 0){
            cout << tmp.step << '\n';
            return;
        }

        table[tmp.x][tmp.y] = '#';

        togo.push( Walk(tmp.x + 1, tmp.y + 2, tmp.step + 1) );
        togo.push( Walk(tmp.x - 1, tmp.y + 2, tmp.step + 1) );
        togo.push( Walk(tmp.x + 1, tmp.y - 2, tmp.step + 1) );
        togo.push( Walk(tmp.x - 1, tmp.y - 2, tmp.step + 1) );

        togo.push( Walk(tmp.x + 2, tmp.y + 1, tmp.step + 1) );
        togo.push( Walk(tmp.x - 2, tmp.y + 1, tmp.step + 1) );
        togo.push( Walk(tmp.x + 2, tmp.y - 1, tmp.step + 1) );
        togo.push( Walk(tmp.x - 2, tmp.y - 1, tmp.step + 1) );
    }
    cout << "-1\n";
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> table[i][j];
            if(table[i][j] == 'K'){
                posxK = i;
                posyK = j;
            }
        }
    }
    BFS(posxK, posyK);
    return 0;
}