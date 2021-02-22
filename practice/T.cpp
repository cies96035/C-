#include<iostream>
#include<vector>
using namespace std;
using vi = vector<int>;

const int DontCare = 2;
const int True = 1;
const int False = 0;

int s, tmp;
int state[64];

//return don't care
bool canUse(int num[6], int I){
    int n = 0;
    bool flg = true;
    if(I == 6){
        for(int i = 5; i >= 0; i--){
            n = 2 * n + num[i];
        }
        if(state[n] != False){
            return true;
        }
    }

    if(num[I] != DontCare){
        return canUse(num, I + 1);
    }else{
        num[I] = 0;
        flg = flg && canUse(num, I + 1);
        num[I] = 1;
        flg = flg && canUse(num, I + 1);
    }
    return flg;
}

void Force(){
    int arr[6];
    for(int i = 0; i < 729; i++){
        for(int j = 0, tmpi = i; j < 6; j++){
            arr[j] = tmpi % 3;
            tmpi /= 3;
        }
    }
}
string op;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> op >> s;
    cin >> op;
    if(op == ".m"){
        while(cin >> op && op != ".d"){
            tmp = 0;
            for(int i = 0; i < s; i++){
                tmp = tmp * 2 + op[i] - '0';
            }
            state[tmp] = True;
        }
    }
    if(op == ".d"){
        while(cin >> op){
            tmp = 0;
            for(int i = 0; i < s; i++){
                tmp = tmp * 2 + op[i] - '0';
            }
            state[tmp] = DontCare;
        }
    }
    return 0;
}