#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 5;
ll preSum[MAX_N][5];
int  maxIdx[5][2];
map<int, int> val;
string str;
ll calAns(int a, int b){ // replace ath to b
    cout << a << ' ' << b << endl;
    int tmp;
    int MI = 0;
    ll ans = 0;
    rvep(i, 4, 0){
        tmp =  maxIdx[i][0];
        if(i == b){
            if(a > tmp){
                tmp = a;
            }
            ans += MI > a ? -val[i] : val[i];
        }else if(tmp == a){
            tmp = maxIdx[i][1];
        }
        int dx = 
        ans -= preSum[MI][i] * val[i];
        ans += (preSum[str.size()][i] - preSum[MI + 1][i]) * val[i];
        cout << tmp << ' ';
        MI = max(tmp, MI);
    cout <<ans << endl;
    }
    cout << endl;
    return ans;
}
void f(){
    cin >> str;
    int sign = 1;
    rep(i, 0, 5)  maxIdx[i][0] =  maxIdx[i][1] = 0;
    rep(i, 0, str.size()){
        rep(j, 0, 5){
            preSum[i + 1][j] = preSum[i][j];
            if(str[i] - 'A' == j){
                preSum[i + 1][j]++;
                maxIdx[j][1] = maxIdx[j][0];
                maxIdx[j][0] = i;
            }
        }
    }
    
    ll ans = -1e18;
    rep(i, 0, str.size()){
        ll sum = 0;
        rep(j, 0, 5){
            ans = max(ans, calAns(i, j));
        }
    }
    cout << ans << '\n';

}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int v = 1;
    rep(i, 0, 5){
        val[i] = v;
        v *= 10;
    }
    int t = 1;
    cin >> t;
    while(t--) f();
    
    return 0;
}