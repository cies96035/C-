#include<iostream>
#include<queue>
using namespace std;
using pii = pair<int,int>;

const int MAX_HEIGHT = 10000;
const int MAX_RC = 60;

queue<pii> flood;
pii S;

int R, C;
char Map[MAX_RC][MAX_RC];
int vis[MAX_RC][MAX_RC];
int visid;
int height[MAX_RC][MAX_RC];
int MinRoad;
void Init(){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            height[i][j] = MAX_HEIGHT;
        }
    }
    MinRoad = MAX_HEIGHT;
}

struct ROAD{
    int x;
    int y;
    int depth;
    ROAD(int a, int b, int c){
        x = a;
        y = b;
        depth = c;
    }
    ROAD(){
        x = y = depth = 0;
    }
};

void GetHeight(int x, int y, int depth){

    queue<ROAD> togo;
    togo.push( ROAD(x, y, depth) );
    while(!togo.empty()){
        x = togo.front().x;
        y = togo.front().y;
        depth = togo.front().depth;
        togo.pop();

        if(x < 0 || y < 0 || x >= R || y >= C){
            continue;
        }else if(vis[x][y] == visid){
            continue;
        }else if(Map[x][y] == 'X' || Map[x][y] == 'D'){
            continue;
        }

        vis[x][y] = visid;
        if(depth < height[x][y]){
            height[x][y] = depth;
        }
        
        togo.push( ROAD(x - 1, y, depth + 1) );
        togo.push( ROAD(x + 1, y, depth + 1) );
        togo.push( ROAD(x, y - 1, depth + 1) );
        togo.push( ROAD(x, y + 1, depth + 1) );
    }
}

bool GetRoad(int x, int y, int depth){

    queue<ROAD> togo;
    togo.push( ROAD(x, y, depth) );
    while(!togo.empty()){
        x = togo.front().x;
        y = togo.front().y;
        depth = togo.front().depth;
        togo.pop();

        if(x < 0 || y < 0 || x >= R || y >= C){
            continue;
        }else if(height[x][y] <= depth){
            continue;
        }else if(Map[x][y] == 'X'){
            continue;
        }else if(Map[x][y] == 'D'){
            MinRoad = depth;
            return true;
        }

        Map[x][y] = 'X';
        
        togo.push( ROAD(x - 1, y, depth + 1) );
        togo.push( ROAD(x + 1, y, depth + 1) );
        togo.push( ROAD(x, y - 1, depth + 1) );
        togo.push( ROAD(x, y + 1, depth + 1) );
    }
    return false;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> R >> C;
    Init();

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> Map[i][j];
            if(Map[i][j] == 'S'){
                S = pii(i, j);
            }else if(Map[i][j] == '*'){
                flood.push(pii(i, j));
            }
        }
    }

    while(!flood.empty()){
        visid++;
        GetHeight(flood.front().first, flood.front().second, 0);
        flood.pop();
    }
    if( GetRoad(S.first, S.second, 0) ){
        cout << MinRoad << '\n';
    }else{
        cout << "KAKTUS\n";
    }
    

    return 0;
}
/*
-10 -7 -6 -1 0 2 5  6  8
-7  -3  2  5 6 8 10 11 12
0 ~ 4
-10 12
-10 11
-10 10
5
*/