#include<iostream>
#include<queue>
using namespace std;

const int Move[5][2] ={
    {0, -1},
    {0, 1},
    {-1, 0},
    {1, 0},
    {0, 0}
};
const int toggle[3][3] = {
    256, 128, 64,
    32, 16, 8,
    4, 2, 1
};

int P;
int n;
int vised[1000];
int visId;
char tmpc;

struct FLIP{
    int depth;
    int id;
    FLIP(){}
    FLIP(int DEPTH, int ID){
        depth = DEPTH;
        id = ID;
    }
};

int findStep(int n){
    visId++;
    
    int tmp, tmpI, tmpJ;

    queue<FLIP> togo;
    togo.push(FLIP(0, n));
    vised[n] = visId;
    
    FLIP cur;
    while(!togo.empty()){
        cur = togo.front();
        togo.pop();

        if(cur.id == 0){
            return cur.depth;
        }

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                tmp = cur.id;
                for(int k = 0; k < 5; k++){
                    tmpI = i + Move[k][0];
                    tmpJ = j + Move[k][1];
                    if(0 <= tmpI && tmpI < 3 && 0 <= tmpJ && tmpJ < 3){
                        tmp ^= toggle[tmpI][tmpJ];
                    }
                }
                if(vised[tmp] != visId){
                    vised[tmp] = visId;
                    togo.push(FLIP(cur.depth + 1, tmp));
                }
            }
        }
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> P;
    while(P--){
        n = 0;
        for(int i = 0; i < 9; i++){
            cin >> tmpc;
            n = 2 * n + (tmpc == '*');
        }
        cout << findStep(n) << '\n';
    }
    return 0;
}