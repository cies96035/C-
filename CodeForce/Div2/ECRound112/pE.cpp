#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 300005;
int n, m;
ll Min = 1000000000000;
struct S{
    int l, r, w;
    bool operator<(const S &x){
        if(w != x.w){
            return w < x.w;
        }
        if(l != x.l){
            return l < x.l;
        }
        if(r != x.r){
            return r < x.r;
        }
    }
}s[MAX_N];
int L = Min, R = -Min;
queue<S> qs;
bool flg;
int curMin;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    rep(i, 0, n){
        cin >> s[i].l >> s[i].r >> s[i].w;
    }
    sort(s, s + n);
    rep(i, 0, n){
        flg = false;
        if(s[i].l < L){
            L = s[i].l;
            flg = true;
        }
        if(s[i].r > R){
            R = s[i].r;
            flg = true;
        }
        qs.push(s[i]);
        if(L == 1 && R == m){
            Min = min(Min,)
        }
    }
    return 0;
}