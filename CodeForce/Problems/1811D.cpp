#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

int fib[50];
void f(){
    int n, x, y;
    cin >> n >> y >> x;
    bool flg = true;
    rvep(i, n, 2){
        // cout << x << ' ' << y << ' ' << fib[i] + 1 << ' ' << fib[i + 1] - fib[i] << endl;
        if(x <= fib[i + 1] - fib[i]){
            swap(x, y);
        }else if(x >= fib[i] + 1){
            x = fib[i + 1] - x + 1;
            swap(x, y);
        }else{
            flg = false;
            break;
        }
    }
    if(flg)cout << "YES\n";
    else cout << "NO\n";
    // cout << flush;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t = 1;
    fib[0] = fib[1] = 1;
    rep(i, 2, 50){
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    cin >> t;
    while(t--) f();
    
    return 0;
}