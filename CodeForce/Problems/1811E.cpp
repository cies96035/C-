#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

void f(){
    ll k, kk;
    cin >> k;
    string str;
    while(k){
        kk = k % 9;
        if(kk < 4){
            str += kk + '0';
        }else{
            str += kk + '0' + 1;
        }
        k /= 9;
    }
    reverse(str.begin(), str.end());
    cout << str << '\n';
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