#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t, n;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        cout << n / 3 + (n % 3 == 1) << ' ' << n / 3 + (n % 3 == 2) << '\n';
    }
    return 0;
}