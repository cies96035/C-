#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rrep(i, a, b) for(int i = a; i <= b; i++)

const int sp[] = {0, 0, 6, 28, 96};
int n;

void solve(ll x){
    if(x < 5){
        cout << sp[x] << '\n';
    }else{
        cout << ((x*x*x*x + 24 * x - 9 * x*x - 16) >> 1) << '\n';
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    rrep(i, 1, n){
        solve(i);
    }
    return 0;
}
/*
1: 0 sp case
2: (4 * 0) / 2
3: (4 * 2 + 4 * 2 + 1 * 0) / 2
4: (4 * 2 + 8 * 3 + 4 * 4) / 2
5: (4 * 2 + 8 * 3 + 8 * 4 + 4 * 6 + 1 * 8) / 2
...
n: (4 * 2 + 8 * 3 + (4 * n - 12) * 4 + (4 * n - 16) * 6 + (n * n - 8n + 16) * 8)
n: (8 * n * n - 24 * n + 16)
-> [ n * n * (n * n - 1) - (8 * n * n - 24 * n + 16) ] / 2 = (n^4 - 9*n^2 + 24n - 16) / 2
*/