#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t;
ll x, y, n;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;
    while(t--){
        cin >> x >> y;
        n = max(x, y);
        if(n & 1){
            swap(x, y);
        }
        if(x < y) cout << (n - 1) * (n - 1) + x << '\n';
        else cout << n * n + 1 - y << '\n';
    }
    return 0;
}