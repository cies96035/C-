#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

ll two[64];
ll n;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    two[0] = 1;
    rep(i, 1, 63){
        two[i] = two[i - 1] << 1;
    }
    cin >> n;
    bitset<100> m(n);
    m = (n ^ (n + 1));
    cout << (n ^ (n + 1)) << endl;
    
    return 0;
}

/*
1101011011 odd ->
1101011100


1101011011
1101010111
1101001111
1100111111
*/