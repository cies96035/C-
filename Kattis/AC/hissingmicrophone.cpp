#include<iostream>
using namespace std;

char c;
char lc;
bool hiss;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    lc = -1;
    while(cin >> c){
        if(lc == c && c == 's'){
            hiss = true;
        }
        lc = c;
    }
    if(hiss){
        cout << "hiss\n";
    }else{
        cout << "no hiss\n";
    }
    return 0;
}