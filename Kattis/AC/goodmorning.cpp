#include<bits/stdc++.h>
using namespace std;

set<int> key;
const int Board[5][4] = {
    1, 2, 3, -1,
    4, 5, 6, -1,
    7, 8 ,9, -1,
    -1, 0, -1, -1,
    -1, -1, -1, -1
};
void Find(int x, int y, int num){
    if(num > 200 || Board[x][y] == -1){
        return;
    }
    key.insert(num);
    if(num || Board[x][y]){
        Find(x, y, num * 10 + Board[x][y]);
    }
    Find(x, y + 1, num);
    Find(x, y + 1, num * 10 + Board[x][y]);
    Find(x + 1, y, num);
    Find(x + 1, y, num * 10 + Board[x][y]);
}

int T, k;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    Find(0, 0, 0);
    key.insert(0);
    cin >> T;
    while(T--){
        cin >> k;
        if( *key.lower_bound(k) - k < k - *(--key.lower_bound(k)) ){
            cout << *key.lower_bound(k) << '\n';
        }else{
            cout << *(--key.lower_bound(k)) << '\n';
        }
    }

    return 0;
}