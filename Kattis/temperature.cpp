#include<iostream>
#include<iomanip>
using namespace std;
using ld = long double;

ld X, Y;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> X >> Y;
    
    if(Y == 1){
        if(X == 0){
            cout << "ALL GOOD\n";
        }else{
            cout << "IMPOSSIBLE\n";
        }
    }else{
        Y -= 1;
        cout << fixed << setprecision(8) <<-(X / Y) << '\n';
    }

    return 0;
}