#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_M = 100005;
int t, m;
int arr[2][MAX_M];
int presum[2][MAX_M];
int presum2[MAX_M];
ll DP[2][MAX_M];
ll Min = 1000000000;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        Min = 1000000000;
        cin >> m;
        rep(i, 0, 2){
            presum[i][0] = 0;
            rep(j, 0, m){
                cin >> arr[i][j];
                presum[i][j + 1] = presum[i][j] + arr[i][j];
            }
        }
        DP[0][0] = 0;
        DP[1][0] = presum[0][m] - presum[0][1];
        rep(i, 0, m){
            DP[0][i] = presum[1][i];
            DP[1][i] = max(presum[1][i], presum[0][m] - presum[0][i + 1]);
            Min = min(Min, DP[1][i]);// << endl;
        }
        cout << Min << '\n';
    }
    return 0;
}