#include<iostream>
using namespace std;

const int MAX_N = 30;
const int DICE = 250;

int T, N;
int vis[DICE][MAX_N][MAX_N];
char Forest[MAX_N][MAX_N];
int visid;

int getState(int F, int L, int D){
   return 36 * F + 6 * L + D;
}

void RightRotate(int L, int D, int &nxL, int &nxD){
    nxL = D;
    nxD = 5 - L;
}

void LeftRotate(int L, int D, int &nxL, int &nxD){
    nxL = 5 - D;
    nxD = L;
}

void FrontRotate(int F, int D, int &nxF, int &nxD){
    nxF = D;
    nxD = 5 - F;
}

void BackRotate(int F, int D, int &nxF, int &nxD){
    nxF = 5 - D;
    nxD = F;
}

bool findPath = 0;
int Sx, Sy;
int nxF, nxL, nxD;

void DFS(int x, int y, int F, int L, int D){

    if(findPath){
        return;
    }else if(x < 0 || y < 0 || x >= N || y >= N){
        return;
    }else if(Forest[x][y] == '*'){
        return;
    }else if(D == 4 && Forest[x][y] == 'H'){
        findPath = true;
        return;
    }

    int currentState = getState(F, L, D);
    if(vis[ currentState ][x][y] == visid){
        return;
    }
    
    vis[ currentState ][x][y] = visid;

    FrontRotate(F, D, nxF, nxD);
    DFS(x - 1, y, nxF, L, nxD);

    BackRotate(F, D, nxF, nxD);
    DFS(x + 1, y, nxF, L, nxD);

    LeftRotate(L, D, nxL, nxD);
    DFS(x, y - 1, F, nxL, nxD);

    RightRotate(L, D, nxL, nxD);
    DFS(x, y + 1, F, nxL, nxD);

    return;
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;

    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> Forest[i][j];
                if(Forest[i][j] == 'S'){
                    Sx = i;
                    Sy = j;
                }
            }
        }

        findPath = false;
        visid++;
        DFS(Sx, Sy, 3, 4, 5);

        if(findPath){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
    return 0;
}