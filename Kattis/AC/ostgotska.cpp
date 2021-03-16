#include<iostream>
using namespace std;

string ipt;
int cnt, aeCnt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> ipt){
        if(ipt.find("ae") != -1){
            aeCnt++;
        }
        cnt++;
    }
    if(4 * cnt <= 10 * aeCnt){
        cout << "dae ae ju traeligt va\n";
    }else{
        cout << "haer talar vi rikssvenska\n";
    }
    return 0;
}