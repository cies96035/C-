#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

void f(){
    string str;
    char c;
    rep(i, 0, 8){
        rep(j, 0, 8){
            cin >> c;
            if(c != '.'){
                str += c;
            }
        }
    }
    cout << str << '\n';
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--){
        f();
    }
    return 0;
}