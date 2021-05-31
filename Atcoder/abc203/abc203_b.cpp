#include<bits/stdc++.h>
using namespace std;

int N, K;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> K;
    
    int sum = N * (N + 1) / 2 * K * 100 + K * (K + 1) / 2 * N;
    cout << sum << '\n';
    return 0;
}