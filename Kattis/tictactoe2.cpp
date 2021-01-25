#include<iostream>
using namespace std;

#define StateAmount 60000
bool TicTacToe[StateAmount];
//0 unfound, 1 found
char c[9];

void Init(int n, bool player)
{
    if(TicTacToe[n])
        return;

    int table[9];
    TicTacToe[n] = 1;

    for(int i = n, j = 0; j < 9; i /= 3, j++)
        table[j] = i % 3;
    
    for(int i = 0; i < 3; i++)
        if(
            table[3 * i + i] != 0 && 
            (table[3 * i + 0] == table[3 * i + 1] && table[3 * i + 0] == table[3 * i + 2] ||
            table[i] == table[3 + i] && table[i] == table[6 + i])
        )
            return;
    if(table[4] != 0 && table[0] == table[4] && table[4] == table[8])
        return;
    if(table[4] != 0 && table[2] == table[4] && table[4] == table[6])
        return;

    for(int i = 1 , j = 0 ; j < 9; i *= 3, j++)
        if(table[j] == 0)
            Init(n + i * (player + 1), !player);
}
void Solve()
{
    int n = 0;
    for(int i = 0; i < 9; i++)
    {
        int s = c[i] == '.' ? 0 : c[i] == 'X' ? 1 : 2;
        n = n * 3 + s;
    }
    cout << (TicTacToe[n] ? "yes\n" : "no\n") ;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    Init(0, 0);
    int t;
    cin >> t;
    while(t--)
    {
        for(int i = 0; i < 9; i++)
            cin >> c[i];
        Solve();
    }
    return 0;
}