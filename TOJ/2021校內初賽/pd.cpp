#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int n, k, a, presum, ans;
set<int> s;
set<int>::iterator tmp;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> k;
    rep(i, 0, n){
        cin >> a;
        presum += a, presum %= k;
        tmp = s.upper_bound(presum);
        if(tmp != s.end()){
            if(k + presum - *tmp > ans){
                ans = k + presum - *tmp;
            }
        }else if(presum > ans){
            ans = presum;
        }
        s.insert(presum);
    }
    cout << ans << '\n';
    return 0;
}