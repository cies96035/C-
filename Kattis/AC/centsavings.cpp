#include<iostream>
#include<climits>
using namespace std;

const int MAX_N = 2020;
const int MAX_D = 22;

int n, d;
int DP[MAX_N][MAX_D];
int arr[MAX_N];

int Saving(int x){
    int remain = x % 10;
    if(remain < 5){
        return x -= remain;
    }else{
        return x + 10 - remain;
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> d;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        DP[i][0] = DP[i - 1][0] + arr[i];
    }
    for(int i = 1; i <= d; i++){
        DP[0][i] = 1e9;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < d; j++){
            DP[i + 1][j + 1] = min(Saving(DP[i + 1][j]), DP[i][j + 1] + arr[i + 1]);
            //min(DON'T CUT, ADD CUT)
        }
    }
    cout << Saving(DP[n][d]) << '\n';
    return 0;
}