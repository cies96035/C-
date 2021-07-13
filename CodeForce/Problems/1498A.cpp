#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int digitSum(ll x){
    int ans = 0;
    while(x){
        ans += x % 10;
        x /= 10;
    }
    return ans;
}
ll Gcd(ll a, ll b){
    while((a %= b) && (b %= a));
    return a + b;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    ll n;
    cin >> t;
    while(t--){
        cin >> n;
        while(Gcd(n, digitSum(n)) == 1){
            n++;
        }
        cout << n << '\n';
    }
    return 0;
}