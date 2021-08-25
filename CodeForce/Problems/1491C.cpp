#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i <= b; i++)

const int MAX_N = 5e4 + 5;
ll t, n, tmp;
ll S[MAX_N], BIT[MAX_N];
ll ans = 0;
void modify(int x, int val){
    while(x < MAX_N){
        BIT[x] += val;
        x += x & -x;
    }
    return;
}
ll query(int x){
    ll ans = 0;
    while(x > 0){
        ans += BIT[x];
        x -= x & -x;
    }
    return ans;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        rep(i, 1, n){
            cin >> S[i];
        }
        memset(BIT, 0, sizeof(BIT));
        ans = 0;
        rep(i, 1, n){
            tmp = query(i);
            if(S[i] > tmp){
                ans += S[i] - tmp - 1;
            }else{
                modify(i + 1, tmp - S[i] + 1);
                modify(i + 2, -(tmp - S[i] + 1));
            }
            modify(i + 2, 1);
            modify(min(n, S[i] + i) + 1, -1);
        }
        cout << ans << '\n';
    }
    return 0;
}