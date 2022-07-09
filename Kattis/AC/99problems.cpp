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
    
    int N;
    cin >> N;
    if( N / 100 * 100 + 99 - N <= N - N / 100 * 100 + 1 || N < 49 ) cout << N / 100 * 100 + 99 << '\n';
    else cout << N / 100 * 100 - 1 << '\n';
    return 0;
}