#include<iostream>
#include<queue>
using namespace std;

typedef pair<int,int> pii;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    const int Mx[4] = {1, 1, -1, -1} , My[4] = {1, -1, 1, -1};
    char Sx, Sy;
    char Ex, Ey;
    while(cin >> Sx >> Sy >> Ex >> Ey)
    {
        cout << "To get from "<<Sx<<Sy<<" to "<<Ex<<Ey<<" takes ";
        Sx -= 'a';
        Ex -= 'a';
        Sy -= '1';
        Ey -= '1';

        int vis[8][8] = {0};

        queue<pii> togo;
        togo.push( pii(Sx, Sy) );

        while(!togo.empty())
        {
            int cx = togo.front().first;
            int cy = togo.front().second;
            togo.pop();
            if( vis[cx][cy] == -1 )
                continue;
            if(cx == Ex && cy == Ey)
            {
                cout << vis[cx][cy] << " knight moves.\n";
                break;
            }

            for(int i = 0; i < 4; i++)
            {
                int NextX = Mx[i] * 2 + cx;
                int NextY = My[i] * 1 + cy;

                if( NextX < 0 || NextX > 7 || NextY < 0 || NextY > 7)
                    continue;
                    
                vis[NextX][NextY] = vis[cx][cy] + 1;
                togo.push( pii(NextX, NextY) );
            }
            
            for(int i = 0; i < 4; i++)
            {
                int NextX = Mx[i] * 1 + cx;
                int NextY = My[i] * 2 + cy;

                if( NextX < 0 || NextX > 7 || NextY < 0 || NextY > 7)
                    continue;

                vis[NextX][NextY] = vis[cx][cy] + 1;
                togo.push( pii(NextX, NextY) );
            }

            vis[cx][cy] = -1;
        }
    }
    return 0;
}
