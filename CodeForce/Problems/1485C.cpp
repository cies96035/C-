#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i <= b; i++)

int t;
int x, y;
ll ans;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> x >> y;
        ans = 0;
        for(int i = 1, tmp, sx = sqrt(x); i <= sx && i < y; i++){
            tmp = x / i - 1;
            if(i < tmp){
                ans += min(tmp, y) - i;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}