#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        cout << (k - 1) / (n - 1) * n + (k - 1) % (n - 1) + 1 << '\n';
    }
    return 0;
}