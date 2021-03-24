#include<iostream>
#include<algorithm>
using namespace std;
using pii = pair<int, int>;

const int MAX_RC = 1010;

struct DEPTH{
    pii pos;
    int depth;
    bool operator < (const DEPTH & x) const{
        return depth < x.depth;
    }
}D[MAX_RC * MAX_RC];

struct DSET{
    pii s;
    int depth;
    bool used;
};
DSET **dSet;
bool cl[MAX_RC][MAX_RC]; // connect left
bool cr[MAX_RC][MAX_RC]; // connect right
int r, c;
int dS;

void Init(){
    dSet = new DSET*[r];
    for(int i = 0; i < r; i++){
        dSet[i] = new DSET[c];
        for(int j = 0; j < c; j++){
            dSet[i][j].s = pii(i, j);
            dSet[i][j].used = false;
        }
        cl[i][0] = true;
        cr[i][c - 1] = true;
    }
    return;
}

pii Find(pii x){
    return x == dSet[x.first][x.second].s ?
    x : dSet[x.first][x.second].s = Find(dSet[x.first][x.second].s);
}

bool Union(pii a, pii b){
    if(b.first < 0 || b.first >= r || b.second < 0 || b.second >= c){
        return false;
    }
    a = Find(a);
    b = Find(b);
    if(dSet[b.first][b.second].used){
        if(cl[b.first][b.second]){
            cl[a.first][a.second] = true;
        }
        if(cr[b.first][b.second]){
            cr[a.first][a.second] = true;
        }
        if(cl[a.first][a.second] && cr[a.first][a.second]){
            return true;
        }
        dSet[b.first][b.second].s = dSet[a.first][a.second].s;
    }
    return false;
}
pii Nghbr(pii x, int dir){
    if(dir == 0){
        x.first++;
    }else if(dir == 1){
        x.first--;
    }else if(dir == 2){
        x.second++;
    }else{
        x.second--;
    }
    return x;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> r >> c;
    Init();
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> dSet[i][j].depth;
            D[dS].pos = pii(i, j);
            D[dS].depth = dSet[i][j].depth;
            dS++;
        }
    }
    sort(D, D + dS);

    for(int i = 0; i < dS; i++){
        dSet[D[i].pos.first][D[i].pos.second].used = true;
        for(int j = 0; j < 4; j++){
            if( Union(D[i].pos, Nghbr(D[i].pos, j)) ){
                cout << dSet[D[i].pos.first][D[i].pos.second].depth << '\n';
                i = dS;
                j = 4;
            }
        }
    }
    return 0;
}