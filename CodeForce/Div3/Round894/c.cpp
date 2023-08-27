#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 5;
int a[MAX_N];
int b[MAX_N];
void f(){
    int n;
    cin >> n;
    rrep(i, 1, n){
        cin >> a[i];
    }
    rrep(i, 1, n){
        if(a[i] > n){
            cout << "NO\n";
            return;
        }else if(i >= 2){
            rvep(j, a[i - 1], a[i] + 1){
                b[j] = i - 1;
            }
        }
    }
    rvep(j, a[n], 0){
        b[j] = n;
    }
    // rrep(i, 1, n){
    //     cout << b[i] << ' ';
    // }cout << endl;
    rep(i, 1, n){
        if(a[i] != b[i]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    // 2 1 1 1 1 1
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while(t--) f();
    
    return 0;
}