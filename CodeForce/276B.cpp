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
    
    int cnt = 0;
    bool charamount[256] = {0};
    string str;
    cin >> str;
    for(auto c : str){
        charamount[c] ^= 1;
    }
    rep(i, 0, 256){
        cnt += charamount[i];
    }
    if(cnt <= 1 || cnt & 1){
        cout << "First\n";
    }else{
        cout << "Second\n";
    }
    
    return 0;
}