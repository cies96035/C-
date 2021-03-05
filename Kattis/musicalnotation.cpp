#include<iostream>
using namespace std;

int n;
char table[14][1000];
string note;
int line;
int col = 3;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 0; i < 7; i++){
        table[i][0] = 'G' - i;
        table[i + 7][0] = 'g' - i;
        table[i][1] = table[i + 7][1] = ':';
        table[i][2] = table[i + 7][2] = ' ';
    }

    for(int i = 0; i < n; i++){
        cin >> note;
        if('A' <= note[0] && note[0] <= 'Z'){
            line = 'G' - note[0];
        }else{
            line = 'g' - note[0] + 7;
        }
        if(note.size() == 1){
            table[line][col] = '*';
            col += 2;
        }else{
            for(int i = '0'; i < note[1]; i++){
                table[line][col++] = '*';
            }
            col++;
        }
    }
    
    for(int i = 0; i < 14; i++){
        for(int j = 0; j < col - 1; j++){
            if(table[i][j]){
                cout << table[i][j];
            }else{
                if(i == 1 || i == 3 || i == 5 || i == 7 || i == 9 || i == 13){
                    cout << '-';
                }else{
                    cout << ' ';
                }
            }
        }
        cout << '\n';
    }
    return 0;
}