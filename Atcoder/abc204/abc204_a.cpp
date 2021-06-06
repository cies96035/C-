#include<bits/stdc++.h>
using namespace std;

int x, y;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> x >> y;
    if(x == y){
        cout << x << '\n';
    }else if(x != 0 && y != 0){
        cout << 0 << '\n';
    }else if(x != 1 && y != 1){
        cout << 1 << '\n';
    }else if(x != 2 && y != 2){
        cout << 2 << '\n';
    }
    return 0;
}