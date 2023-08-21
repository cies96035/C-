#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 1e5 + 5;
bool arr[MAX_N];
pll seg[MAX_N];
int segIdx;
int query[MAX_N], queryIdx;
int preSum[MAX_N];
int n, m;
bool check(int x){
    rrep(i, 1, n){
        arr[i] = 0;
    }
    rep(i, 0, x){
        arr[query[i]] = 1;
    }
    rrep(i, 1, n){
        preSum[i] = preSum[i - 1] + arr[i];
    }
    rep(i, 0, m){
        int l = seg[i].second - seg[i].first + 1;
        if(preSum[seg[i].second] - preSum[seg[i].first - 1] > l / 2){
            return true;
        }
    }
    return false;

}
void f(){
    queryIdx = segIdx = 0;
    cin >> n >> m;
    rep(i, 0, m){
        int l, r;
        cin >> l >> r;
        seg[segIdx++] = {l, r};
    }
    int q;
    cin >> q;
    rep(i, 0, q){
        cin >> query[queryIdx++];
    }
    int l = 0, r = q + 1, mid;
    while(l < r){
        mid = (l + r) >> 1;
        if(check(mid)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    cout << (l <= q ? l : -1) << '\n';
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