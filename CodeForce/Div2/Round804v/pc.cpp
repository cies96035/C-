/*
1 2 4 0 5 3
1 2 5 0 4 3
1 4 2 0 5 3
1 5 2 0 4 3
x o o x o x


1 3 7 2 5 0 6 4
x o o o o x o x


*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const ll MOD = 1e9 + 7;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<pll> nums;
        rep(i, 0, n){
            nums.push_back({i, i});
            cin >> nums.back().first;
        }
        sort(nums.begin(), nums.end());
        int l = min(nums[0].second, nums[1].second),
            r = max(nums[0].second, nums[1].second);
        int x = r - l - 1;
        ll ans = 1;
        
        rep(i, 2, nums.size()){
            if(l < nums[i].second && nums[i].second < r){
                ans *= x;
                ans %= MOD;
                x--;
            }else if(nums[i].second < l){
                x += l - nums[i].second - 1;
                l = nums[i].second;
            }else{
                x += nums[i].second - r - 1;
                r = nums[i].second;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}