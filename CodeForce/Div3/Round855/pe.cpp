#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

void f(){
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    map<char, int> cnt;
    for(auto c : s){
        cnt[c]++;
    }
    for(auto c : t){
        cnt[c]--;
        if(cnt[c] < 0){
            cout << "NO\n";
            return;
        }
    }
    for(int i = 0; i < s.size(); i++){
        if(s[i] != t[i]){
            if(!(i >= k || n - i - 1 >= k)){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";

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