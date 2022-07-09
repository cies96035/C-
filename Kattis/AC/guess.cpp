#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

string ipt;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int l = 1, r = 1001;
    while(l < r){
        int m = (l + r) >> 1;
        cout << m << endl;
        cin >> ipt;
        if(ipt == "lower"){
            r = m;
        }else if(ipt == "higher"){
            l = m + 1;
        }else{
            break;
        }
    }
    return 0;
}