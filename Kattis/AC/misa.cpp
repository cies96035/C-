#include<iostream>
using namespace std;
using pii = pair<int, int>;

const int MAX_RC = 60;
const int Move[8][2] = {
    {-1, -1}, {0, -1}, {1, -1}, 
    {-1, 0}, {1, 0}, 
    {-1, 1}, {0, 1}, {1, 1}
};
int R, C;
bool Misa[MAX_RC][MAX_RC];
char tmp;
int cnt, cntMirko, cntTmp;
int nx, ny;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> tmp;
            if(tmp == 'o'){
                Misa[i][j] = true;
            }
        }
    }

    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cntTmp = 0;
            for(int k = 0; k < 8; k++){
                nx = i + Move[k][0];
                ny = j + Move[k][1];
                if(Misa[nx][ny]){
                    if(Misa[i][j]){
                        cnt++;
                    }else{
                        cntTmp++;
                    }
                }
            }
            if(cntTmp > cntMirko){
                cntMirko = cntTmp;
            }
        }
    }

    cout << cnt / 2 + cntMirko << '\n';
    return 0;
}