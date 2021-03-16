#include<iostream>
using namespace std;

const int MAX_MN = 110;
char sky[MAX_MN][MAX_MN];
int cnt;
int n, m;
void RE(int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= m){
        return;
    }else if(sky[x][y] == '#'){
        return;
    }
    sky[x][y] = '#';
    RE(x - 1, y);
    RE(x + 1, y);
    RE(x, y - 1);
    RE(x, y + 1);
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int Case = 1; cin >> n >> m; Case++){
        cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> sky[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(sky[i][j] != '#'){
                    RE(i, j);
                    cnt++;
                }
            }
        }
        cout << "Case " << Case << ": " << cnt << '\n';
    }
    return 0;
}