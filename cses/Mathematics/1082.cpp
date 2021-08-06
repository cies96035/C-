#include<bits/stdc++.h>
using ll = long long;
const ll MOD = 1000000007;
ll n, ans, t;
int main()
{
    std::cin >> n;
    for(int i = 1, sn = sqrt(n); i <= sn; ++i){
        t = n / i % MOD;
        ans += i * t + (sn + t + 1) * (t - sn) / 2;
        if(ans > 1e18){
            ans %= MOD;
        }
    }
    std::cout << ans % MOD << '\n';
    return 0;
}