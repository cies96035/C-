#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

ll t, x, n;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> x >> n;
        ll d;
        if(n % 4 == 0){
            d = 0;
        }else if(n % 4 == 1){
            d = -n;
        }else if(n % 4 == 2){
            d = 1;
        }else{
            d = n + 1;
        }
        if(x % 2){
            d *= -1;
        }
        cout << x + d << '\n';
    }
    return 0;
}


/*
0 0
1 -1
2 1
3 4

4 0
5 -5
6 1
7 8

x 0
a -a
b 1
c c + 1

0 1 0
1 2 1
2 0 -1
3 -3 -4
4 1 0
5 6 5
6 0 -1
7 -7 -8



*/