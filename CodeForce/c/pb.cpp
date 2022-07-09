#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

int strtoi(string str){
    int ans = 0;
    for(auto c : str){
        ans = ans * 10 + c;
    }
    return ans;
}
string itostr(int x){
    string ans;
    rep(i, 0, 5){
        ans += (x % 10);
        x /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
const int MAX_N = 10000;
bool ngood[MAX_N];
int f[10][10];
bool check2(string s){
    int a = f[0][s[0]];
    int b = f[a][s[1]];
    int c = f[b][s[2]];
    int d = f[c][s[3]];
    int e = f[d][s[4]];
    if(e == 0){
        return true;
    }
    return false;
}
bool check(int x){
    string s = itostr(x);
    int a = f[0][s[1]];
    int b = f[a][s[2]];
    int c = f[b][s[3]];
    int d = f[c][s[4]];
    // cout << d << endl;
    s = itostr(s[1] * 10000 + s[2] * 1000 + s[3] * 100 + s[4] * 10 + d);
    string t;
    rep(i, 0, 5){
        t = s;
        rep(j, 0, 10){
            t[i] = j;
            if(s != t){
                if(check2(t)){
                    return false;
                }
            }
        }
    }
    rep(i, 0, 4){
        t = s;
        swap(t[i], t[i + 1]);
        if(t != s)
            if(check2(t)){
                return false;
            }
    }
    return true;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    rep(i, 0, 10){
        rep(j, 0, 10){
            cin >> f[i][j];
        }
    }
    // cout << check(2016) << endl;
    int cnt = 0;
    rep(i, 0, 10000){
        if(!check(i)){
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}