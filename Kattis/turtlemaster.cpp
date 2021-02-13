#include<iostream>
using namespace std;
using pii = pair<int,int>;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    const int S = 9;
    const pii m[4] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    char table[S + 1][S + 1];
    int x, y;
    int Dx, Dy;
    for(int i = 1; i < S; i++)
        for(int j = 1; j < S; j++)
        {
            cin >> table[i][j];
            if(table[i][j] == 'T')
            {
                x = j;
                y = i;
            }
            else if(table[i][j] == 'D')
            {
                table[i][j] = '.';
                Dx = j;
                Dy = i;
            }
        }
    
    for(int i = 0; i < S; i++)
        table[i][S] = table[S][i] = table[0][i] = table[i][0] = 'C';

    string op;
    int dir = 3;

    cin >> op;
    for(auto s : op)
    {
        if(s == 'F')
        {
            int newx = x + m[dir].first;
            int newy = y + m[dir].second;
            if(table[newy][newx] == '.'){
                swap(table[y][x], table[newy][newx]);
                x = newx;
                y = newy;
            }else{
                break;
            }
        }
        else if(s == 'L'){
            dir = (dir + 1) % 4;
        }
        else if(s == 'R'){
            dir = (dir + 3) % 4;
        }
        else if(s == 'X'){
            int newx = x + m[dir].first;
            int newy = y + m[dir].second;
            if(table[newy][newx] == 'I'){
                table[newy][newx] = '.';
            }else{
                break;
            }
        }
    }
    if(x == Dx && y == Dy){
        cout << "Diamond!\n";
    }else{
        cout << "Bug!\n";
    }
    return 0;
}