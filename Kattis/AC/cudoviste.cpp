#include<iostream>
using namespace std;

const int MAX_RC = 55;

char cityMap[MAX_RC][MAX_RC];
const int M[4][2] = {
    {0, 0},
    {0, -1},
    {-1, 0},
    {-1, -1},
};
int R, C;
int squCnt[5];
int cnt;

inline int check(char c){
    if(c == 'X'){
        return 1;
    }else if(c == '#'){
        return -1;
    }else{
        return 0;
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> cityMap[i][j];
        }
    }
    for(int i = 1; i < R; i++){
        for(int j = 1; j < C; j++){
            cnt = 0;
            for(int k = 0; k < 4; k++){
                if(check(cityMap[i + M[k][0]][j + M[k][1]]) == 1){
                    cnt++;
                }else if(check(cityMap[i + M[k][0]][j + M[k][1]]) == -1){
                    cnt = -1;
                    break;
                }
            }
            if(cnt >= 0){
                squCnt[cnt]++;
            }
        }
    }
    for(int i = 0; i <= 4; i++){
        cout << squCnt[i] << '\n';
    }
    return 0;
}