#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)
const int MAX_N = 2e5;
int a[MAX_N];

void f(){
    int n;
    cin >> n;
    rep(i, 0, n){
        cin >> a[i];
    }
    sort(a, a + n);
    if(a[0] == a[n - 1]) cout << "-1\n";
    else{
        vector<int> b, c;
        rep(i, 0, n) {
            if(a[i] == a[0]) b.push_back(a[i]);
            else c.push_back(a[i]);
        }
        cout << b.size() << ' ' << c.size() <<'\n';
        for(auto i : b){
            cout << i << ' ';
        }cout << '\n';
        for(auto i : c){
            cout << i << ' ';
        }cout << '\n';
    }
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