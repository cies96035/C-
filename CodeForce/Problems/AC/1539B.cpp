#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 100010;
int n, q;
int preSum[MAX_N];
int l, r;
char c;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> q;
    rep(i, 0, n){
        cin >> c;
        preSum[i + 1] = preSum[i] + c - 'a' + 1;
    }
    while(q--){
        cin >> l >> r;
        cout << preSum[r] - preSum[l - 1] << '\n';
    }
    return 0;
}