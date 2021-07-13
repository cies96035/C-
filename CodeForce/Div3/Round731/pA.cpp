#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t;
int xa, ya, xb, yb, xf, yf;
int ans;
int dis(int a, int b, int c, int d){
    return abs(a - b) + abs(c - d);
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> xa >> ya >> xb >> yb >> xf >> yf;
        ans = dis(xa, xb, ya, yb);
        if(xa == xb){
            if(
                xa == xf &&
                (
                ya < yf && yf < yb ||
                yb < yf && yf < ya
                )
            ){
                ans += 2;
            }
        }else if(ya == yb){
            if(
                ya == yf &&
                (
                xa < xf && xf < xb ||
                xb < xf && xf < xa
                )
            ){
                ans += 2;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}