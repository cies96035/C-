#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
using pii = pair<int,int>;
const int MAX_N = 8;
int vis[MAX_N][MAX_N];
int visId;
int T;
int Max;

struct Walk{
    int x;
    int y;
    int step;
    Walk(int a, int b, int c){
        x = a;
        y = b;
        step = c;
    }
    Walk(){
        x = 0;
        y = 0;
        step = 0;
    }
    bool operator < (const Walk &b){
        return y == b.y ? x < b.x : y > b.y;
    }
};

vector<Walk> place;

void BFS(int x, int y){

    queue<Walk> togo;
    togo.push( Walk(x, y, 0) );

    while(!togo.empty()){
        Walk tmp = togo.front();
        togo.pop();
        if(tmp.x < 0 || tmp.y < 0 || tmp.x >= MAX_N || tmp.y >= MAX_N){
            continue;
        }else if(vis[tmp.x][tmp.y] == visId){
            continue;
        }

        if(Max < tmp.step){
            Max = tmp.step;
            place.clear();
            place.emplace_back(tmp);
        }else if(Max == tmp.step){
            place.emplace_back(tmp);
        }

        vis[tmp.x][tmp.y] = visId;

        togo.push( Walk(tmp.x + 1, tmp.y + 2, tmp.step + 1) );
        togo.push( Walk(tmp.x - 1, tmp.y + 2, tmp.step + 1) );
        togo.push( Walk(tmp.x + 1, tmp.y - 2, tmp.step + 1) );
        togo.push( Walk(tmp.x - 1, tmp.y - 2, tmp.step + 1) );

        togo.push( Walk(tmp.x + 2, tmp.y + 1, tmp.step + 1) );
        togo.push( Walk(tmp.x - 2, tmp.y + 1, tmp.step + 1) );
        togo.push( Walk(tmp.x + 2, tmp.y - 1, tmp.step + 1) );
        togo.push( Walk(tmp.x - 2, tmp.y - 1, tmp.step + 1) );
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    char x;
    int y;
    cin >> T;
    while(T--){
        visId++;
        cin >> x >> y; 
        Max = 0;
        BFS(x - 'a', y - 1);
        sort(place.begin(), place.end());
        cout << place[0].step;
        for(vector<Walk>::iterator i = place.begin(); i != place.end(); i++){
            cout << ' ' << char(i->x + 'a') << i->y + 1;
        }
        cout << '\n';
        place.clear();
    }
    
    return 0;
}