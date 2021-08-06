#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 1e6 + 5;
const int INF = 0x3fffffff;

int n, DP[MAX_N];
int Minstep(int x){
    if(x < 0){
        return INF;
    }
    if(x == 0){
        return 1;
    }
    if(DP[x] != 0){
        return DP[x];
    }
    int Min = INF;
    for(int t = x; t; t /= 10){
        if(t % 10){
            Min = min(Min, Minstep(x - t % 10));
        }
    }
    return DP[x] = Min + 1;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    Minstep(n);
    cout << DP[n] - 1 << '\n';
    return 0;
}