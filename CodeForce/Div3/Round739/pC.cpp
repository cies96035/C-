#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ll t;
    ll k, x;
    cin >> t;
    while(t--){
        cin >> k;
        x = sqrt(k - 1);
        int xx = x * x + x + 1;
        if(k < xx){
            cout << k - x * x << ' ' << x + 1 << '\n';
        }else{
            cout << x + 1 << ' ' << (x + 1) * (x + 1) - k + 1 << '\n';
        }
    }
    return 0;
}