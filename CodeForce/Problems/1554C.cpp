#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t, n, m;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n >> m;
        int ans = 0;
        for(int i = 31; i >= 0; i--){
            if( !(n & (1 << i)) && (n | ((1 << i) - 1)) <= m ){
                ans |= 1 << i;
                n |= (1 << i);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}