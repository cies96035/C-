#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const string DICT = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const string END = "ACCESS GRANTED";
const string WL = "ACCESS DENIED (5 ms)";

string ipt, ans;
int len;
int strtoint(string str){
    int num = 0;
    rep(i, 1, str.size()){
        num = num * 10 + str[i] - '0';
    }
    return num;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    rep(i, 0, 20){
        ans += 'a';
        cout << ans << endl;
        getline(cin, ipt);
        if(ipt == END) return 0;
        if(ipt != WL){
            len = i + 1;
            break;
        }
    }
    
    rep(i, 0, len){
        rep(j, 0, DICT.size()){
            ans[i] = DICT[j];
            cout << ans << endl;
            cin >> ipt >> ipt;
            if(ipt == "GRANTED") return 0;
            
            cin >> ipt;
            if(strtoint(ipt) >= 23 + i * 9) {cin >> ipt; break;}
            cin >> ipt;
        }
    }
    return 0;
}