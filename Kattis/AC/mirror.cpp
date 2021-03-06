#include<iostream>
using namespace std;

int T;
int R, C;
char table[30][30];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    for(int Test = 1; Test <= T; Test++){
        cin >> R >> C;
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                cin >> table[i][j];
            }
        }
        cout << "Test " << Test << '\n';
        for(int i = R - 1; i >= 0 ; i--){
            for(int j = C - 1; j >=0; j--){
                cout << table[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}