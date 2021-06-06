#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 110;
const int MAX_T = 101000;
int N;
int sum;
int ans = 2e9;
int T[MAX_N];
bool DP[MAX_T];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> T[i];
        sum += T[i];
    }
    DP[0] = true;
    for(int i = 0; i < N; i++){
        for(int j = MAX_T - 1; j >= T[i]; j--){
            if(DP[j - T[i]]){
                DP[j] = true;
                ans = min(ans, max(sum - j, j));
            }
        }
    }
    cout << ans << '\n';
    return 0;
}