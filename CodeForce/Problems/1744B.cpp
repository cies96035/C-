#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 1e5 + 5;
ll n, q;
ll a, type, x;
ll sum[2], cnt[2];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--){
        cnt[0] = cnt[1] = 0;
        sum[0] = sum[1] = 0;
        cin >> n >> q;
        rep(i, 0, n){
            cin >> a;
            cnt[a & 1]++;
            sum[a & 1] += a;
        }
        while(q--){
            cin >> type >> x;
            if(((type + x) & 1) != type){
                ll diff = x * cnt[type];
                sum[(type + x) & 1] += sum[type] + diff;
                sum[type] = 0;
                cnt[(type + x) & 1] = n;
                cnt[type] = 0;
            }else{
                sum[type] += x * cnt[type];
            }
            cout << sum[0] + sum[1] << '\n';
        }
    }
    return 0;
}