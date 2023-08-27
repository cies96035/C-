#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 25;
string str[MAX_N];
void f(){
    const string vika = "vika";
    int n, m;
    cin >> n >> m;
    rep(i, 0, n){
        cin >> str[i];
    }
    int idx = 0;
    rep(i, 0, m){
        rep(j, 0, n){
            if(idx < vika.size() && vika[idx] == str[j][i]){
                idx++;
                break;
            }
        }
    }
    cout << (idx == 4 ? "YES\n" : "NO\n");
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