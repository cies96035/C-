#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)
const int MAX_N = 2e5 + 5;
pll arr[MAX_N];
int ans[MAX_N];
void f(){
    int n;
    cin >> n;
    bool flg = true;
    rrep(i, 1, n) ans[i] = -1;
    rep(i, 1, n){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr + 1, arr + n);
    rep(i, 1, n){
        if(ans[arr[i].second] == -1){
            ans[arr[i].second] = arr[i].first;
        }
        if(ans[arr[i].second + 1] == -1){
            ans[arr[i].second + 1] = arr[i].first;
        }
    }
    rrep(i, 1, n){
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while(t--) f();
    
    return 0;
}