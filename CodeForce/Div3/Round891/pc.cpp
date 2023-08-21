#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

void f(){
    int n;
    cin >> n;
    int N = n * (n-1) / 2;
    int b;
    map<int, int> cnt;
    rep(i, 0, N){
        cin >> b;
        cnt[-b]++;
    }
    cout << 1000000000;
    int idx = 1;
    for(auto &i : cnt){
        while(i.second > 0){
            cout << ' ' << -i.first;
            i.second -= idx++;
        }
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