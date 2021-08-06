#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

char chess[8][8];
bool col[8], l[15], r[15];
int cnt;
void eq(int x, int y){
    if(chess[x][y] == '*' || col[y] || l[x - y + 7] || r[x + y]){
        return;
    }
    if(x == 7){
        cnt++;
        return;
    }
    col[y] = l[x - y + 7] = r[x + y] = true;
    for(int i = 0; i < 8; i++){
        eq(x + 1, i);
    }
    col[y] = l[x - y + 7] = r[x + y] = false;
    return;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    rep(i, 0, 8){
        rep(j, 0, 8){
            cin >> chess[i][j];
        }
    }

    rep(i, 0, 8){
        eq(0, i);
    }

    cout << cnt << '\n';
    return 0;
}