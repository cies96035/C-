#include<iostream>
using namespace std;

int x, y;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> x >> y;
    if(x > 0 && y > 0){
        cout << 1 << '\n';
    }else if(y > 0){
        cout << 2 << '\n'; 
    }else if(x > 0){
        cout << 4 << '\n'; 
    }else{
        cout << 3 << '\n';
    }
    return 0;
}