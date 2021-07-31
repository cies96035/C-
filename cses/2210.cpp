#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MOD = 1000000007;
ll n;
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
    cin >> n;
    cout << 
    (
        (qpow(2, n * n) - qpow(2, n * n / 2) ) * qpow(4, MOD - 2) + 
        (qpow(2, n * n / 2) - qpow(2, n * n / 4) ) * qpow(2, MOD - 2) + 
        qpow(2, n * n / 4) ) % MOD<< endl;
    return 0;
}


/*
2 x 2
00 01 11 10 11 11
00 00 00 01 01 11
 1  4  4  2  4  1

ab
cd

ab
ba

3 x 3

1: 3 (n)(n - 1) / 2
aba
bcb
aba

abcda
dghgj
chmho


2: 5 (n * n / 2 + 1)
abc
ded
cba

abcde
fghij
klmlk

4: 9

4 x 4
4:
abcd
efgh
ijkl
mnop
//16252
16320
(2^16 - 2^8) / 4

2:
abcd
efgh
hgfe
dcba
120
(2^8 - 2^4 / 2)

1:
abca
cddb
bddc
acba
16
(2^4) / 1
*/