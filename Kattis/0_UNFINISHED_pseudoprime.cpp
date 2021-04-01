#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll P, A;
ll fpow(ll a, ll p, const ll M){
    ll base = 1;
    while(p){
        if(p & 1){
            base *= a;
            base %= M;
        }
        a *= a;
        a %= M;
        p /= 2;
    }
    return base;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    while(cin >> P >> A && P){
        if(fpow(A, P, P) == A){
            cout << "yes\n";
        }else{
            cout << "no\n";
        }
    }
    return 0;
}