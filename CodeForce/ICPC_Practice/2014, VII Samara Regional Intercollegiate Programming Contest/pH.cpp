#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

string str;
const string D = "desmond";
int n;
int a;
char c;
bool check(int l, int r){
    l = max(0, l);
    r = min(int(str.size() - D.size()), r);
    // cout << l << ' ' << r << endl;
    rrep(i, l, r){
        rep(j, 0, D.size()){
            if(str[i + j] != D[j]){
                break;
            }
            if(j == D.size() - 1){
                return true;
            }
        }
    }
    return false;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int ans = -1;
    cin >> str;
    cin >> n;
    if(check(0, str.size())){
        ans = 0;
    }
    rep(i, 0, n){
        cin >> a >> c;
        str[a - 1] = c;
        // cout << str << endl;
        if(check(a - 8, a + 8) && ans == -1){
            ans = i + 1;
        }
    }
    if(ans != -1){
        cout << "I love you, Desmond!\n" << ans << '\n';
    }else{
        cout << "Goodbye, my love!\n";
    }
    return 0;
}