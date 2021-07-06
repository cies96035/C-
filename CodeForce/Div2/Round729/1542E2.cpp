#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void extGcd (ll a, ll b, ll &x, ll &y){
    ll t;
    if(b == 0) x = 1, y = 0;
    else extGcd(b, a % b, x, y), t = x, x = y, y = t - a / b * y;
}
ll Gcd(ll a, ll b){
    while( (a %= b) && (b %= a) );
    return a + b;
}
ll n, a, b;
bool InSet(ll n){
    cout << n << endl;
    if(b == 1 || n % b == 1){
        return true;
    }
    if(n <= 0 || a == 1){
        return false;
    }
    if(a != 1 && n % a == 0){
        while(n % a == 0){
            n /= a;
        }
        return InSet(n);
    }else if( n % Gcd(a, b) != 0){
        return false;
    }
    ll x, y;
    ll L = a / Gcd(a, b); 
    extGcd(a, b, x, y);
    y *= n / Gcd(a, b);
    if(y < 0){
        y -= y / L * L - L; 
    }else{
        y -= y / L * L;
    }
    return InSet(n - y * b);
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll t;
    cin >> t;
    while(t--){
        cin >> n >> a >> b;
        if( InSet(n) ){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
    return 0;
}