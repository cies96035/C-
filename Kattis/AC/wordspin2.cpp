#include<iostream>
using namespace std;

string s1, s2;
int cnt, lastcnt = -1;
int lastState, curState;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> s1 >> s2;
    for(int i = 0; i < s1.size(); i++){
        s1[i] -= s2[i];
    }
    
    while(lastcnt != cnt){
        lastcnt = cnt;
        lastState = 0;
        for(int j = 0; j < s1.size(); j++){
            if(s1[j] > 0){
                curState = 1;
                s1[j]--;
            }else if(s1[j] < 0){
                curState = -1;
                s1[j]++;
            }else{
                curState = 0;
            }
            if(curState != 0 && curState != lastState){
                cnt++;
            }
            lastState = curState;
        }
    }

    cout << cnt << '\n';
    return 0;
}