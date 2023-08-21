#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 10;
int trap[MAX_N];
void f(){
    int n, a;
    unordered_map<int, int> cnt;
    cin >> n;
    rrep(i, 1, n){
        trap[i] = 0;
        cin >> a;
        if(a <= n){
            cnt[a]++;
        }
    }
    rrep(i, 1, n){
        int j = i;
        while(j <= n){
            trap[j] += cnt[i];
            j += i;
        }
    }
    int ans = 0;
    rrep(i, 1, n){
        ans = max(ans, trap[i]);
    }
    cout << ans << '\n';
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        f();
    }
    return 0;
}