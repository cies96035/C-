#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int n, k;
int DFS(int a, int b, int x){
    // cout << x << ' ' << a << ' ' << b << endl;
    if(x >= n){
        // if(a >= b){
        //     cout << a << ' ' << b << endl;
        // }
        return a >= b;
    }
    int sum = 0;
    rep(i, 0, (1 << k)){
        sum += DFS(a & i, b ^ i, x + 1);
    }
    return sum;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // cout << (3 ^ 3 ^ 3 ^ 3 ^ 3) << endl;
    cin >> n >> k;
    cout << DFS((1 << 30) - 1, 0, 0);
    return 0;
}