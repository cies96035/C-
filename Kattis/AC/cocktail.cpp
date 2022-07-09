#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 1000;
int N, T;
int t[MAX_N];
bool flg;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> T;
    rep(i, 0, N) cin >> t[i];
    sort(t, t + N);
    rep(i, 1, N){
        if( t[i] < T * i + 1 ) flg = true;
    }
    if(!flg) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}