#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 1e5 + 5;
int n, a[MAX_N];
int q, x, y;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    bool f1 = false, f2 = false, f3 = false;
    cin >> n;
    if(n > 10) f3 = true;
    rep(i, 0, n){
        cin >> a[i];
        if(i > 0 && a[i - 1] > a[i]){
            f1 = true;
        }
    }
    cin >> q;
    rep(i, 0, q){
        cin >> x >> y;
        if(x > y) f2 = true;
        if(f1) cout << "-1\n";
        x--, y--;
        x = (x + y) >> 1;
        cout << a[x] << '\n';
    }
    return 0;
}