#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

ull x, y;
int StanWin;
bool flg;
void gcd(ull a, ull b){
    if(b == 0){
        return;
    }
    if(a % b){
        if(a / b > 1 && StanWin == -1){
            StanWin = flg;
        }else if(a / b == 1){
            flg = !flg;
        }
    }
    a %= b;
    gcd(b, a);
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> x >> y && (x || y)){
        StanWin = -1; //Unsure
        flg = true;
        gcd(x, y);
        if(StanWin == -1){
            StanWin = flg;
        }
        if(StanWin){
            cout << "Stan wins\n";
        }else{
            cout << "Ollie wins\n";
        }
    }
    return 0;
}