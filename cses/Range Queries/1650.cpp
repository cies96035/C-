#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i <= b; i++)

const int MAX_N = 200005;
int n, q;
int a, b;
int preXor[MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> q;
    rep(i, 1, n){
        cin >> preXor[i];
        preXor[i] ^= preXor[i - 1];
    }
    while(q--){
        cin >> a >> b;
        cout << (preXor[b] ^ preXor[a - 1]) << '\n';
    }
    return 0;
}