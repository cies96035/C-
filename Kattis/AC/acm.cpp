#include<iostream>
using namespace std;

int penalty[26];
bool ac[26];

int m;
char p;
string sub;
int acCnt, timeCnt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> m && m != -1 && cin >> p >> sub){
        p -= 'A';
        if(sub == "right"){
            if(!ac[p]){
                acCnt++;
                timeCnt += m + penalty[p];
            }
        }else{
            penalty[p] += 20;
        }
    }
    cout << acCnt << ' ' << timeCnt << '\n';
    return 0;
}