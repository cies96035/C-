#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int MAX_C = 50500;

int playerCnt[3];
int stren[3];
int kayak[MAX_C], C;
pii strength[6];


//check if the speed is good
bool check(int speed){
    static bool goodFlg;
    static int playerNumber[3], a, b;
    for(int i = 0; i < 3; i++){
        playerNumber[i] = playerCnt[i];
    }
    for(int i = 0; i < C; i++){
        goodFlg = false;
        for(int j = 0; j < 6; j++){
            if(strength[j].first * kayak[i] >= speed){

                a = strength[j].second / 3;
                b = strength[j].second % 3;

                if(a == b && playerNumber[a] >= 2 || a != b && playerNumber[a] && playerNumber[b]){
                    goodFlg = true;
                    playerNumber[a]--;
                    playerNumber[b]--;
                    break;
                }
            }
        }
        if(!goodFlg){
            return false;
        }
    }
    return true;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i = 0; i < 3; i++){
        cin >> playerCnt[i];
        C += playerCnt[i];
    }
    C /= 2;

    for(int i = 0; i < 3; i++){
        cin >> stren[i];
    }

    for(int i = 0; i < C; i++){
        cin >> kayak[i];
    }
    sort(kayak, kayak + C);

    for(int i = 0, strId = 0; i < 3; i++){
        for(int j = i; j < 3; j++){
            strength[strId++] = pii(stren[i] + stren[j], 3 * i + j);
        }
    }
    sort(strength, strength + 6);

    //binary search
    int MinId = 0, MaxId = 200002000, MiddleId;
    while(MinId < MaxId){
        MiddleId = (MinId + MaxId) / 2;
        if(check(MiddleId)){
            MinId = MiddleId + 1;
        }else{
            MaxId = MiddleId;
        }
    }
    cout << MinId - 1 << '\n';

    return 0;
}