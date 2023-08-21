#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5+5;
int t;
int n;
int a[MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        bool f1 = 0, f2 = true;
        cin >> n;
        rep(i, 0, n){
            cin >> a[i];
            if(i != 0 && a[i] > a[i - 1]){
                f1 = true;
            }else if(i != 0 && a[i] < a[i - 1]){
                if(f1){
                    f2 = false;
                }
            }
        }
        cout << (f2 ? "YES" : "NO") << '\n';
    }
    return 0;
}