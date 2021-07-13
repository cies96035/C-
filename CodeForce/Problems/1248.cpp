#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i <= b; i++)

int n;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    cout << 3 * n + 4 << '\n';
    cout << "0 0\n1 0\n";
    rep(i, 1, n){
        rep(j, -1, 1){
            cout << i + j << ' ' << i << '\n';
        }
    }
    cout << n << ' ' << n + 1 << '\n';
    cout << n + 1 << ' ' << n + 1 << '\n';
    return 0;
}