#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_R = 1000005;
const int MAX_SR = 1005;
const int MOD = 1000000007;
int primeF[MAX_R];
ll n;
ll getDivSum(ll val, ll x){
    if(x == 1){
        return val;
    }
    if(primeF[x]){
        return ( getDivSum(val * primeF[x], x / primeF[x]) + getDivSum(val, x / primeF[x]) ) % MOD;
    }else{
        return ( getDivSum(val * x, 1) + getDivSum(val, 1) ) % MOD;
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i = 2; i < MAX_SR; i++){
        if(!primeF[i]){
            for(int j = i * i; j < MAX_R; j += i){
                primeF[j] = i;
            }
        }
    }
    cin >> n;
    cout << getDivSum(1, n) << '\n';
    /*
    1 3 4 7  6  12
    1 4 8 15 21 33
    */

    return 0;
}