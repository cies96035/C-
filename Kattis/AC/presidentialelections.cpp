#include<iostream>
#include<climits>
using namespace std;
using ll = long long;

const int MAX_S = 2020;
ll DP[MAX_S];
ll S;
ll D, C, F, U;
ll Min;
ll totalDelegates;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    Min = INT_MAX;
    for(int i = 0; i < MAX_S; i++){
        DP[i] = INT_MAX;
    }

    DP[0] = 0;
    cin >> S;
    for(int i = 0; i < S; i++){
        cin >> D >> C >> F >> U;
        totalDelegates += D;
        F = (C + F + U + 2) / 2 - C;
        if(F > U){
            continue;
        }
        if(F < 0){
            F = 0;
        }
        for(int j = MAX_S - 1; j >= D; j--){
            if(DP[j - D] < INT_MAX && DP[j] > DP[j - D] + F){
                DP[j] = min(DP[j - D] + F, DP[j]);
            }
        }
    }
    for(int i = totalDelegates / 2 + 1; i <= totalDelegates; i++){
        if(DP[i] < Min){
            Min = DP[i];
        }
    }
    if(Min < INT_MAX){
        cout << Min << '\n';
    }else{
        cout << "impossible\n";
    }


    return 0;
}