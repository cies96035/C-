#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int DP[100][2];
int t;
string s;
void Init(){
    rep(i, 0, 100){
        DP[i][0] = DP[i][1] = 0;
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;
    while(t--){
        Init();
        cin >> s;
        for(auto c : s){
            c -= '0';
            for(int i = 0; i < 10; i++){
                DP[10 * i + c][1] = DP[10 * i + c][0];
                DP[10 * c + i][0] = DP[10 * c + i][1] + 1;
            }
        }
        int MaxLen = 0;
        rep(i, 0, 100){
            if(i / 10 != i % 10){
                MaxLen = max(DP[i][1] * 2, MaxLen);
            }else{
                MaxLen = max(DP[i][0], MaxLen);
            }
        }
        cout << s.size() - MaxLen << '\n';
    }
    return 0;
}