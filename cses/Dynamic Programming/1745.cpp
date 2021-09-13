#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i <= b; i++)

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n, x, sum = 0;
    bitset<100005> dp = 1;
    cin >> n;
    while(n--){
        cin >> x;
        dp |= dp << x;
        sum += x;
    }
    cout << dp.count() - 1 << '\n';
    rep(i, 1, sum){
        if(dp[i]){
            cout << i << ' ';
        }
    }
    cout << '\n';
    return 0;
}