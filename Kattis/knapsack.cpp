#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int MAX_CN = 2200;

int c, n;
pii DP[MAX_CN][MAX_CN];
pii object[MAX_CN];
set<int> ansSet;
int MaxId;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> c >> n){
        MaxId = 0;
        ansSet.clear();
        for(int i = 0; i <= c; i++){
            for(int j = 0; j <= n; j++){
                DP[i][j].first = 0;
                DP[i][j].second = -1;
            }
        }

        for(int i = 0; i < n; i++){
            cin >> object[i].first >> object[i].second;
        }
        for(int i = 0; i < n; i++){
            for(int j = c; j >= object[i].second; j--){
                if(DP[j - object[i].second][i].first + object[i].first >= DP[j][i].first){
                    DP[j][i + 1].first = DP[j - object[i].second][i].first + object[i].first;
                    DP[j][i + 1].second = i;
                    if(DP[MaxId][i].first < DP[j][i + 1].first){
                        MaxId = j;
                    }
                }else{
                    DP[j][i + 1] = DP[j][i];
                }
            }
        }
        ///cout << MaxId << endl;
        //cout << DP[MaxId].first << endl;
        //system("PAUSE");
        while(DP[MaxId][n].second != -1){
            ansSet.insert(DP[MaxId][n].second);
            MaxId -= object[DP[MaxId][n].second].second;
            //cout << "A" << MaxId << DP[MaxId][n].second << endl;
            n--;
        }
        cout << ansSet.size() << '\n';
        for(auto i : ansSet){
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}