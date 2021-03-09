#include<iostream>
using namespace std;
using ull = unsigned long long;

const int MAX_N = 1000100;

ull n, ipt;
ull Max, Mul;
ull preSum[MAX_N], preSum2[MAX_N];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> ipt;
        preSum[i + 1] = preSum[i] + ipt;
        preSum2[i + 1] = preSum2[i] + ipt * ipt;
    }
    for(int i = 1; i <= n; i++){
        Mul = preSum2[i - 1] * (preSum[n] - preSum[i - 1]);
        if(Max < Mul){
            Max = Mul;
        }
    }
    cout << Max << '\n';
    return 0;
}