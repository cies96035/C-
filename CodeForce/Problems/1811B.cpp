#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

int f1(int n, int x){
    if(x > n / 2){
        return x - n / 2;
    }else{
        return n / 2 - x + 1;
    }
}
void f(){
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    cout << abs(max(f1(n, a), f1(n, b)) - max(f1(n, c), f1(n, d))) << '\n';
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