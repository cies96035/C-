#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t;
ll a, b;
ll ans;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(a == b){
            cout << "0 0\n";
        }else{
            if(a > b){
                swap(a, b);
            }
            ans = b - a;
            cout << ans << ' ' << min(a % ans, ans - a % ans) << '\n';
        }
    }
    return 0;
}