#include<iostream>
#include<stack>
using namespace std;
using pii = pair<int, int>;
const int MAX_N = 100100;

int N;
char field[10][MAX_N];
int cnt;

stack<pii> Move;
int pos;

void DFS(int x, int y){
    if(pos != -1){
        return;
    }else if(field[x][y] == 'X'){
        return;
    }else if(y == N - 1){
        pos = x;
        field[x][y] = 'E';
        return;
    }else if(field[x][y] == 'O'){
        return;
    }
    field[x][y] = 'O';


    if(x >= 9){
        DFS(x, y + 1);
    }else{
        DFS(x + 1, y + 1);
    }

    if(x <= 0){
        DFS(x, y + 1);
    }else{
        DFS(x - 1, y + 1);
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < N; j++){
            cin >> field[i][j];
        }
    }
    pos = -1;
    DFS(9, 0);
    for(int i = N - 1; i > 0; i--){
        if(pos < 9 && field[pos + 1][i - 1] == 'O'){
            pos++;
            cnt++;
            continue;
        }else if(pos > 0 && field[pos - 1][i - 1] == 'O'){
            pos--;
            if(cnt != 0){
                Move.push( pii(i, cnt) );
                cnt = 0;
            }
        }else if(pos == 0){
            cnt++;
        }else{
            if(cnt != 0){
                Move.push( pii(i, cnt) );
                cnt = 0;
            }
        }
    }
    if(cnt != 0){
        Move.push( pii(0, cnt) );
        cnt = 0;
    }
    cout << Move.size() << '\n';
    while(!Move.empty()){
        cout << Move.top().first << ' ' << Move.top().second << '\n';
        Move.pop();
    }
    return 0;
}