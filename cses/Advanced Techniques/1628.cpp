#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define all(x, xs) x, x + xs

int n, x, t[40];
ll l[1 << 20], r[1 << 20];

int lid, rid;
void f(int a, const int b, ll sum, ll *s, int &sid){
    if(a == b){
        s[sid++] = sum;
    }else if(sum <= x){
        f(a + 1, b, sum + t[a], s, sid);
        f(a + 1, b, sum, s, sid);
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> x;
    rep(i, 0, n){
        cin >> t[i];
    }

    f(0, n >> 1, 0, l, lid);
    f(n >> 1, n, 0, r, rid);
    sort(all(l, lid));
    sort(all(r, rid));

    ll cnt = 0;
    rep(i, 0, lid){
        cnt += upper_bound(all(r, rid), x - l[i]) - lower_bound(all(r, rid), x - l[i]);
    }
    cout << cnt << '\n';
    return 0;
}