#include<iostream>
using namespace std;

const int MAX_N = 110;
const int MAX_S = 30030;
int n, m;
int manu;
int tmp;
int DP[MAX_N][MAX_S];
int vis[MAX_S];
bool blank;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> manu;
        vis[manu]++;
        DP[i][manu]++;

        for(int j = 0; j < MAX_S; j++){
            if(vis[j]){
                tmp = j + manu;
                if(tmp >= MAX_S){
                    break;
                }

                if(!vis[tmp]){
                    for(int k = 1; k <= i; k++){
                        DP[k][tmp] = DP[k][j];
                    }
                    DP[i][tmp]++;
                }
                vis[tmp]++;
            }
        }
    }

    for(int i = 0; i <m ; i++){
        cin >> tmp;
        if(vis[tmp] == 0){
            cout << "Impossible\n";
        }else if(vis[tmp] > 1){
            cout << "Ambiguous\n";
        }else{
            blank = false;
            for(int j = 1; j <= n; j++){
                while(DP[j][tmp]){
                    if(blank){
                        cout << ' ';
                    }else{
                        blank = true;
                    }
                    cout << j;
                    DP[j][tmp]--;
                }
            }
            cout << '\n';
        }
    }
    return 0;
}