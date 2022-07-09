#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    const int n = 8;
    int b, k;
    cin >> k >> b;
        int sum = 0;
        for(int i = 0; i < (1<<b); i += k){
            cout <<  i ;
            bitset<(size_t)(n)> t = i;
            cout << ' ' << __builtin_popcount(i) <<endl << t.to_string() << endl;
            sum += __builtin_popcount(i);
        }
        cout << sum << endl;
    return 0;
}
/*
0
1
4
12
32
80


1010
->
1010
10100
11
1010
11
11
1001
*/