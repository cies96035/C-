#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 2e5 + 5;
int n, t;
ll k[MAX_N];
bool test(ll x){
    ll s = 0;
    rep(i, 0, n){
        s += x / k[i];
    }
    return s >= t;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> t;
    rep(i, 0, n){
        cin >> k[i];
    }
    ll i = 0, j = (1e18 + 1e17) / n, Mid;
    while(i < j){
        Mid = (i + j) >> 1;
        if(test(Mid)){
            j = Mid;
        }else{
            i = Mid + 1;
        }
    }
    cout << i << '\n';
    return 0;
}