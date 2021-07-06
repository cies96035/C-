#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_N = 400500;
const int M = 1e9 + 7;
int DSU[MAX_N], ans;
int A[MAX_N], B[MAX_N];
void Init(int n){
    for(int i = 1; i <= n; i++){
        DSU[i] = i;
    }
}
int Find(int x){
    return x == DSU[x] ? x : DSU[x] = Find( DSU[x] );
}
void Union(int a, int b){
    if(Find(a) == Find(b)){
        return;
    }
    DSU[Find(a)] = Find(b);
    ans--;
}

ll qpow(ll b, int n){
    ll t = 1;
    while(n){
        if(n & 1){
            t *= b;
            t %= M;
        }
        b *= b;
        b %= M;
        n >>= 1;
    }
    return t;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        ans = n;
        Init(n);
        for(int i = 0; i < n; i++){
            cin >> A[i];
        }
        for(int i = 0; i < n; i++){
            cin >> B[i];
            Union(A[i], B[i]);
        }
        cout << qpow(2, ans) << '\n';
    }
    return 0;
}