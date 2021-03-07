#include<iostream>
#include<iomanip>
#include<climits>
#include<queue>
using namespace std;

#define noDEBUG
const int MAX_NM = 1010;

int words[256];
bool wordsVis[256];
char landMap[MAX_NM][MAX_NM];
int group[MAX_NM][MAX_NM];
bool groupPushed[MAX_NM * MAX_NM];

int n, m;
int groupid;

struct COUNTRY{
    int x, y;
    int w;
    bool operator< (const COUNTRY c)const{
        return w > c.w;
    }
    char c() const{
        return landMap[x][y];
    }
    COUNTRY(int X, int Y, int Depth){
        x = X;
        y = Y;
        w = Depth;
    }
};

priority_queue<COUNTRY> pq;

void DrawGroup(const char &c, int x, int y, const int &id){
    if(x < 0 || x >= n || y < 0 || y >= m){
        return;
    }else if(group[x][y] != 0 || landMap[x][y] != c){
        return;
    }

    group[x][y] = groupid;
    DrawGroup(c, x - 1, y, id);
    DrawGroup(c, x + 1, y, id);
    DrawGroup(c, x, y - 1, id);
    DrawGroup(c, x, y + 1, id);

    DrawGroup(c, x - 1, y - 1, id);
    DrawGroup(c, x - 1, y + 1, id);
    DrawGroup(c, x + 1, y - 1, id);
    DrawGroup(c, x + 1, y + 1, id);
}


void DFS(int x, int y, const int &depth, const int id){
    if(x < 0 || x >= n || y < 0 || y >= m){
        return;
    }else if(group[x][y] == -1){
        return;
    }else if(group[x][y] != id){
        if(!groupPushed[ group[x][y] ]){
            if(words[ landMap[x][y] ] > depth + 1){
                words[ landMap[x][y] ] = depth + 1;
            }
            groupPushed[ group[x][y] ] = true;
            #ifdef DEBUG
                cout << "PUSH" << ' ' << landMap[x][y] << ' ' << x << ' '<< y << ' '<< depth + 1<<endl;
            #endif
            pq.push( COUNTRY(x, y, depth + 1) );
        }
        return;
    }

    group[x][y] = -1;

    DFS(x - 1, y, depth, id);
    DFS(x + 1, y, depth, id);
    DFS(x, y - 1, depth, id);
    DFS(x, y + 1, depth, id);

    DFS(x - 1, y - 1, depth, id);
    DFS(x - 1, y + 1, depth, id);
    DFS(x + 1, y - 1, depth, id);
    DFS(x + 1, y + 1, depth, id);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i = 0; i < 256; i++){
        words[i] = INT_MAX;
    }

    cin >> n >> m;
    
    //input landMap
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> landMap[i][j];
            wordsVis[ landMap[i][j] ] = true;
        }
    }
    wordsVis['W'] = false;

    //group every piece
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(group[i][j] == 0){
                DrawGroup(landMap[i][j], i, j, ++groupid);
            }
        }
    }

    #ifdef DEBUG
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << group[i][j] << ' ';
            }
            cout<<endl;
        }
    #endif

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(landMap[i][j] == 'W' && group[i][j] != -1){
                
                #ifdef DEBUG
                    cout << "W : " << i << ", " << j << ", " << group[i][j] << ", " << words['W'] << endl;
                #endif
                groupPushed[ group[i][j] ] = true;
                DFS(i, j, -1, group[i][j]);
        
                #ifdef DEBUG
                    for(int ii = 0; ii < n; ii++){
                        for(int jj = 0; jj < m; jj++){
                            cout << setw(3) << group[ii][jj];
                        }
                        cout<<endl;
                    }
                    cout << endl;
                #endif
            }
        }
    }
    while(!pq.empty()){
        #ifdef DEBUG
            cout << pq.top().c() <<" : " << pq.top().x << ',' << pq.top().y << ',' << group[pq.top().x][pq.top().y] << ',' << words[pq.top().c()] << endl;
        #endif
        DFS(pq.top().x, pq.top().y, pq.top().w, group[pq.top().x][pq.top().y]);
        pq.pop();
        
        
        #ifdef DEBUG
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << setw(3) << group[i][j];
                }
                cout<<endl;
            }
            cout << endl;
        #endif
    }

    for(int i = 0; i < 256; i++){
        if(wordsVis[i]){
            cout << char(i) << ' ' << words[i] << '\n';
        }
    }
    
    return 0;
}