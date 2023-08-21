#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

int n;
string s[2];
int t, q;
void f(){
    cin >> s[0] >> s[1];
    n = s[0].size();
    cin >> t >> q;

    int diffCnt = 0;
    rep(i, 0, n){
        if(s[0][i] != s[1][i]) diffCnt++;
    }
    queue<pll> block;
    int op;
    rep(i, 0, q){
        cin >> op;
        if(!block.empty() && block.front().second + t == i){
            if(s[0][block.front().first] != s[1][block.front().first]) diffCnt++;
            block.pop();
        }
        if(op == 1){
            int pos;
            cin >> pos;
            pos--;
            block.push({pos, i});
            if(s[0][pos] != s[1][pos]) diffCnt--;
        }else if(op == 2){
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            a--, b--, c--, d--;
            if(s[0][b] != s[1][b]) diffCnt--;
            if(s[0][d] != s[1][d]) diffCnt--;
            swap(s[a][b], s[c][d]);
            if(s[0][b] != s[1][b]) diffCnt++;
            if(s[0][d] != s[1][d]) diffCnt++;
        }else{
            if(diffCnt) cout << "NO\n";
            else cout <<"YES\n";
        }
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