#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t;
ll W, H, w, h;
ll x1, yy1, x2, y2;
ll ans;
bool check(int W, int H, int x1, int yy1, int x2, int y2, int w, int h){
    return
    (x2 <= W && y2 <= H && x1 >= 0 && yy1 >= 0) &&
    ( (x1 >= w) || (yy1 >= h) || (W - x2 >= w) || (H - y2 >= h) ) ;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> W >> H;
        cin >> x1 >> yy1 >> x2 >> y2;
        cin >> w >> h;
        ans = 100000000 + 1000;
        if(check(W, H, x1, yy1, x2, y2, w, h)){
            // cout << "E" << endl;
            ans = 0;
        }
        if(check(W, H, w, yy1, x2 - x1 + w, y2, w, h)){
            // cout << "D" << endl;
            ans = min(ans, abs(w - x1) );
        }
        if(check(W, H, x1, h, x2, y2 - yy1 + h, w, h)){
            // cout << "A" << endl;
            ans = min(ans, abs(h - yy1) );
            //cout << ans << endl;
        }
        if(check(W, H, x1 + W - w - x2, yy1, W - w, y2, w, h)){
            // cout << "B" << endl;
            ans = min(ans, abs(W - w - x2) );
        }
        if(check(W, H, x1, yy1 - y2 + H - h, x2, H - h, w, h)){
            // cout << "C" << endl;
            ans = min(ans, abs(H - h - y2) );
        }
        if(ans > 100000000){
            cout << "-1\n";
        }else{
            cout << ans << '\n';
        }
        // cout << flush << "AAA" << endl;
    }
    return 0;
}