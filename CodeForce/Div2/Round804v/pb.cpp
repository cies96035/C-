#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

void output(int x, bool st){
    rrep(i, 1, x){
        if(i % 4 < 2){
            cout << st << ' ';
        }else{
            cout << !st << ' ';
        }
    }
    cout << '\n';
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t;
    int n, m;
    cin >> t;

    while(t--){
        cin >> n >> m;
        rrep(i, 1, n){
            if(i % 4 < 2)
                output(m, 0);
            else
                output(m, 1);
        }
    }
    return 0;
}