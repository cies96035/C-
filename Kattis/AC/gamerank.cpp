#include<iostream>
using namespace std;

int ranklist[26];
char c;
int curStar = 0;
int curRank = 25;
int strike = 0;

void win(){
    if(curRank == 0){
        return;
    }
    strike++;
    if(curRank >= 6 && strike >= 3){
        curStar++;
    }
    curStar++;
    if(curStar > ranklist[curRank]){
        curStar -= ranklist[curRank];
        curRank--;
    }
}
void lose(){
    if(curRank == 0){
        return;
    }
    strike = 0;
    if(curRank < 20){
        if(curStar == 0){
            curRank++;
            curStar = ranklist[curRank] - 1;
        }else{
            curStar--;
        }
    }else if(curRank == 20 && curStar > 0){
        curStar--;
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i = 1; i <= 5; i++){
        ranklist[20 + i] = 2;
        ranklist[15 + i] = 3;
        ranklist[10 + i] = 4;
        ranklist[5 + i] = 5;
        ranklist[0 + i] = 5;
    }
    while(cin >> c){
        if(c == 'W'){
            win();
        }else{
            lose();
        }
        //cout << c << ':' << curRank <<' '<<curStar << endl;
    }
    if(curRank){
        cout << curRank << '\n';
    }else{
        cout << "Legend\n";
    }
    return 0;
}