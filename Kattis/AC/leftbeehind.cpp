#include<iostream>
using namespace std;

int x, y;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> x >> y && (x || y)){
        if(x + y == 13){
            cout << "Never speak again.\n";
        }else if(x < y){
            cout << "Left beehind.\n";
        }else if(x > y){
            cout << "To the convention.\n";
        }else{
            cout << "Undecided.\n";
        }
    }
    return 0;
}