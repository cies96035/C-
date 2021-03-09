#include<iostream>
using namespace std;

const int Move[4][2] = {
    {0, -1},
    {-1, 0},
    {0, 1},
    {1, 0}
};

int table[4][4];
int op;
void RightRow(int x){
    if(table[x][0] == table[x][1] && table[x][2] == table[x][3]){
        table[x][2] = table[x][0] * 2;
        table[x][3] *= 2;
        table[x][0] = table[x][1] = 0;
        return;
    }
    for(int i = 3; i > 0; i--){
        if(table[x][i - 1] == table[x][i]){
            
        }
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> table[i][j];
        }
    }
    cin >> op;
    return 0;
}