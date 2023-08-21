#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

int n, m;
string s;

bool Check(int l, int r, int *preSum){
    int t = preSum[r + 1] - preSum[l];
    int m = r - t;
    return preSum[m + 1] - preSum[l] == 0;
}
void f(){
    cin >> n >> m;
    cin >> s;
    vector<int> c;
    int preSum[n + 1] = {0};
    rep(i, 0, s.size()){
        if(i == 0) c.push_back(1);
        else if(s[i] != s[i - 1]){
            c.push_back(c.back() + 1);
        }else{
            c.push_back(c.back());
        }
        preSum[i + 1] = s[i] - '0' + preSum[i];
    }

    set<pll> cnt;
    int l, r;
    rep(i, 0, m){
        cin >> l >> r;
        if(Check(l - 1, r - 1, preSum)){
            l = 1; r = 1;
        }
        if(s[l - 1] == '1'){
            if(l >= 2 &&s[l - 2] == '0'){
                l = c[l - 2];
            }else{
                l = -l;
            }
        }else{
            l = c[l - 1];
        }
        if(s[r - 1] == '0'){
            if(r != s.size() && s[r] == '1'){
                r = c[r];
            }else{
                r = -r;
            }
        }else{
            r = c[r - 1];
        }
        cnt.insert({l, r});
        // cout << "(" << l << ", " << r << ")" << endl;
    }
    // cout << endl;
    // for(auto i:cnt)cout << "(" << i.first << ", " << i.second << ")" << ' ';
    cout << cnt.size() << '\n';
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
// 101101 110110 000100

// 