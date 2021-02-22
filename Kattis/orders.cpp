#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_N = 110;
const int MAX_S = 33000;

int n, m;
int tmp;
int DP[MAX_S];
int vis[MAX_S];
int ans[MAX_S], ansId;
int manu[MAX_N];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    vis[0] = 1;
    for(int i = 1; i <= n; i++){
        cin >> manu[i];
        for(int j = manu[i]; j < MAX_S; j++){
            tmp = j - manu[i];
            if(vis[tmp]){
                if(vis[j] == 0 && vis[tmp] != 2){
                    DP[j] = i;
                    vis[j] = true;
                }else{
                    vis[j] = 2;
                }
            }
        }
    }

    cin >> m;
    for(int i = 0; i < m ; i++){
        cin >> tmp;
        if(vis[tmp] == 0){
            cout << "Impossible\n";
        }else if(vis[tmp] == 2){
            cout << "Ambiguous\n";
        }else{
            ansId = 0;
            while(tmp > 0){
                ans[ansId++] = DP[tmp];
                tmp -= manu[DP[tmp]];
            }

            sort(ans, ans + ansId);
            for(int i = 0; i < ansId - 1; i++){
                cout << ans[i] << ' ';
            }
            cout << ans[ansId - 1] << '\n';
        }
    }
    return 0;
}