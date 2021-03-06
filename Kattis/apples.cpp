#include<iostream>
using namespace std;

const int MAX_R = 50500;
const int MAX_C = 11;
string apple[MAX_R];
char grid[MAX_R][MAX_C];
int R, C;
int point;
int appleCnt;
int Top;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        cin >> apple[i];
        grid[i][C] = '\0';
    }

    for(int j = 0; j < C; j++){
        Top = 0;
        for(int i = 0; i <= R; i++){
            if(i == R || apple[i][j] == '#'){
            grid[i][j] = '#';
                for(int k = i - 1; k >= Top; k--){
                    if(appleCnt){
                        grid[k][j] = 'a';
                        appleCnt--;
                    }else{
                        grid[k][j] = '.';
                    }
                }
                Top = i + 1;
            }else if(apple[i][j] == 'a'){
                appleCnt++;
            }
        }
    }
    for(int i = 0 ; i < R; i++){
        cout << grid[i] << '\n';
    }
    return 0;
}