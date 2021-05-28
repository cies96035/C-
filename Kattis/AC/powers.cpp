#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll a, b, ans, M;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> a >> b;
    if(a % 2){
        cout << 0 << '\n';
    }else{
        ans = 1;
        M = a;
        a /= 2;
        while(b){
            if(b % 2){
                ans *= a;
                ans %= M;
            }
            a *= a;
            a %= M;
            b /= 2;
        }
        cout << ans << '\n';
    }
    return 0;
}