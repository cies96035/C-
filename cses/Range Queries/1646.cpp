#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 200005;
int n, q;
int x, a, b;
ll presum[MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> q;
    rep(i, 0, n){
        cin >> x;
        presum[i + 1] = presum[i] + x;
    }
    while(q--){
        cin >> a >> b;
        cout << presum[b] - presum[a - 1] << '\n';
    }
    return 0;
}