#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 1005;
int n, q;
int preSum[MAX_N][MAX_N];
char c;
struct POINT{
    int x, y;
}a, b;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> q;
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> c;
            preSum[i + 1][j + 1] = 
            preSum[i][j + 1] + preSum[i + 1][j] - preSum[i][j];
            if(c == '*'){
                preSum[i + 1][j + 1]++;
            }
        }
    }
    while(q--){
        cin >> a.x >> a.y >> b.x >> b.y;
        a.x--, a.y--;
        cout << preSum[b.x][b.y] - preSum[a.x][b.y] - preSum[b.x][a.y] + preSum[a.x][a.y] << '\n';
    }
    return 0;
}