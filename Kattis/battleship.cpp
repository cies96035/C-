#include<iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    char table[2][35][35];
    bool player;
    int P[2];
    int t;
    int w, h, n;
    int x, y;
    cin >> t;
    while(t--)
    {
        P[0] = P[1] = 0;
        player = 1;
        cin >> w >> h >> n;

        for(int i = 0; i < 2; i++)
            for(int j = h - 1; j >= 0; j--)
                for(int k = 0; k < w; k++)
                {
                    cin >> table[i][j][k];
                    if(table[i][j][k] == '#')
                        P[i]++;
                }

        while(n--)
        {
            cin >> x >> y;
            if(player && (P[0] == 0 || P[1] == 0))
            {
                while(n--)
                    cin >> x >> y;
                break;
            }
            if(table[player][y][x] == '#')
            {
                table[player][y][x] = '_';
                P[player]--;
                if(P[player] == 0)
                    player = !player;
            }
            else
                player = !player;
        }
        if(P[0] && P[1] || (P[0] == 0 && P[1] == 0))
            cout << "draw\n";
        else if(P[0])
            cout << "player one wins\n";
        else
            cout << "player two wins\n";
    }
    return 0;
}