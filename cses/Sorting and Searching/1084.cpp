#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 200005;
int n, m, k;
int a[MAX_N], b[MAX_N];
int aid, bid, cnt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m >> k;
    rep(i, 0, n){
        cin >> a[i];
    }
    rep(i, 0, m){
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + m);
    while(aid < n && bid < m){
        if(abs(a[aid] - b[bid]) <= k){
            aid++;
            bid++;
            cnt++;
        }else if(a[aid] - k > b[bid]){
            bid++;
        }else{
            aid++;
        }
    }
    cout << cnt << '\n';
    return 0;
}