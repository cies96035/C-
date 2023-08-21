#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

int t;
int n, a, b;
bool check(){
    if(n == a && n == b){
        return true;
    }else if(n - a - b > 1){
        return true;
    }
    return false;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    rep(i, 0, t){
        cin >> n >> a >> b;
        if(check()){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
    
    return 0;
}