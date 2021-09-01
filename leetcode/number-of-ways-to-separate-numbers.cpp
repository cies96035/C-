#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)
int numberOfCombinations(string num) {
    const int M = 1e9 + 7;
    for(auto &c : num){
        c -= '0';
    }
    vector<ll> DP(num.size() + 1, 0);
    vector<ll> presum(num.size() + 1, 0);
    for(int j = 1; j <= num.size(); j++){
        for(int i = 0, k = j; (i + j - 1) < num.size(); i++){//[i - j, i - 1], [i, i + j - 1]
            if(i == 0){
                if(num[0] != 0){
                    DP[i + j - 1] = 1;
                }else{
                    DP[i + j - 1] = 0;
                }
            }else if(i < j){
                if(num[i] != 0){
                    DP[i + j - 1] = presum[i - 1];
                }else{
                    DP[i + j - 1] = 0;
                }
            }else{
                while((k + 1) < i + j){
                    if((k < i || num[k] == num[k - j])){
                        k++;
                    }else{
                        break;
                    }
                }
                if(num[i] == 0){
                    DP[i + j - 1] = 0;
                }else if(num[k] < num[k - j]){
                    DP[i + j - 1] = presum[i - 1];
                }else{
                    DP[i + j - 1] = presum[i - 1] + DP[i - 1];
                }
            }
        }
        for(int i = 0; i < num.size(); i++){
            presum[i] += DP[i];
            presum[i] %= M;
        }
        DP[j - 1] = 0;
    }
    return presum[num.size() - 1];
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    string n;
    cin >> n;
    cout << numberOfCombinations(n) << endl;
    return 0;
}
/*
012345
395503
110000
011200
001122
000112
000011
000001

*/