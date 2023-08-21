#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

string str;
void f(){
    cin >> str;
    int flg = str.size();
    rvep(i, str.size() - 1, 0){
        if(i == 0){
            if(str[i] >= '5'){
                cout << "1";
                flg = i;
            }
        }else if(str[i] >= '5'){
            str[i - 1]++;
            flg = i;
        }
    }
    rep(i, 0, str.size()){
        if(i >= flg) cout << '0';
        else cout << str[i];
    }
    cout << '\n';
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