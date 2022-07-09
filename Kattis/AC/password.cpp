#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 600;
int n;
string ipt;
ld nums[MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    rep(i, 0, n){
        cin >> ipt >> nums[i];
    }
    sort(nums, nums + n);
    int k = n;
    ld ans = 0;
    rep(i, 0, n){
        ans += k * nums[i];
        k--;
    }
    cout << fixed << setprecision(5) << ans << '\n';
    return 0;
}