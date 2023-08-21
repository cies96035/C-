#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    string str;
    cin >> str;
    ll cnt = 0, tmp = str.size() - 1;
    rvep(i, str.size() - 1, 0){
        if(str[i] == '1'){
            cnt += tmp - i;
            tmp--;
        }
    }
    if(cnt % 3){
        cout << "Alice\n";
    }else{
        cout << "Bob\n";
    }
    return 0;
}