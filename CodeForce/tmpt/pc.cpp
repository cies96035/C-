#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)
/*
1 : 1
2 : 2 2
3 : 1 6 6
4 : 1 4 12 12
5 : 

*/
int n;
void f(){
    cin >> n;
    vector<int> vi;
    rep(i, 0, n){
        vi.push_back(i + 1);
    }
    ll ans = 0;
    rep(j, 0, n){
        reverse(vi.begin() + j, vi.end());
        ll cnt =0;
        int M = 0;
        rrep(i, 1, n){
            cnt += i * vi[i - 1];
            M = max(i * vi[i - 1], M);
        }
        cnt -= M;
        if(cnt > ans){
            ans = cnt;
        }
        reverse(vi.begin() + j, vi.end());
    }
    // do{
    // }while(next_permutation(vi.begin(), vi.end()));
    cout << ans << '\n';
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