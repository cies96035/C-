#include<iostream>
using namespace std;

int R, C, ZR, ZC;
string s, tmp;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> R >> C >> ZR >> ZC;
    
    for(int i = 0; i < R; i++){
        cin >> s;
        for(auto c : s){
            for(int j = 0; j < ZC; j++){
                tmp += c;
            }
        }
        for(int j = 0; j < ZR; j++){
            cout << tmp << '\n';
        }
        tmp.clear();
    }
    return 0;
}