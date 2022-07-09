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
    int num;
    cin >> str;
    while(str.size() % 3) str = "0" + str;
    rep(i, 0, str.size()){
        if( i % 3 == 0 ) num = 0;
        num = (num << 1) + str[i] - '0';
        if( (i % 3) == 2 ) cout << num;
    }
    cout << endl;
    return 0;
}