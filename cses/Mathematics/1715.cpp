#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MOD = 1000000007;
int cnt[256];
int n;
string str;
ll qpow(ll a, int b){
    ll ans = 1;
    while(b){
        if(b & 1){
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ll ans = 1;
    cin >> str;
    for(auto c : str){
        cnt[c]++;
    }
    for(int i = 1; i <= str.size(); i++){
        ans = ans * i % MOD;
    }
    for(int i = 'a'; i <= 'z'; i++){
        while(cnt[i]){
            ans = ans * qpow(cnt[i], MOD - 2) % MOD;
            cnt[i]--;
        }
    }
    cout << ans << '\n';
    return 0;
}