// 22

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 10;
int arr[MAX_N];
void f(){
    int n, k;
    cin >> n >> k;
    rep(i, 0, n){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int cnt = 1, ans = 1;
    rep(i, 1, n){
        // cout << arr[i] << ' ';
        if(arr[i - 1] + k < arr[i]){
            cnt = 0;
        }
        cnt++;
        // cout << cnt << endl;
        ans = max(cnt, ans);
    }
    cout << n - ans << '\n';
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