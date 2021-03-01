#include<iostream>
using namespace std;

const int R = 5;
const int C = 4;
int table[R][C];
int sum[R], maxr, maxSum;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> table[i][j];
            sum[i] += table[i][j];
        }
        if(maxSum < sum[i]){
            maxSum = sum[i];
            maxr = i;
        }
    }
    cout << maxr + 1 << ' ' << maxSum << '\n';
    return 0;
}