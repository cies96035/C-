#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define X first
#define Y second
const int MAX_NM = 2e5 + 5;
const int MAX_K = 3e5 + 5;

int t, n, m, k;
int x[MAX_NM], y[MAX_NM], cnt[MAX_NM];
ll ans;

void f(const vector<pii> &vpii, int *arr, int as){
    memset(cnt, 0, sizeof(int) * (as + 3));
    int l = 0;
    rep(i, 1, vpii.size()){
        if(vpii[i].X != vpii[i - 1].X){
            rep(j, l, i){
                ans += cnt[ lower_bound(arr, arr + as, vpii[j].Y) - arr ];
            }
            rep(j, l, i){
                cnt[ lower_bound(arr, arr + as, vpii[j].Y) - arr ]++;
            }
            l = i;
        }
    }
    rep(j, l, vpii.size()){
        ans += cnt[lower_bound(arr, arr + as, vpii[j].Y) - arr ];
    }
    rep(j, l, vpii.size()){
        cnt[ lower_bound(arr, arr + as, vpii[j].Y) - arr ]++;
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        vector<pii> ta, tb;
        ans = 0;

        cin >> n >> m >> k;
        rep(i, 0, n)
            cin >> x[i];
        rep(i, 0, m)
            cin >> y[i];

        int a, b, type;
        rep(i, 0, k){
            cin >> a >> b;
            type = 0;
            if(*lower_bound(x, x + n, a) == a){
                type += 1; // |
            }
            if(*lower_bound(y, y + m, b) == b){
                type += 2; // _
            }
            if(type == 1){
                ta.push_back({a, b});
            }else if(type == 2){
                tb.push_back({b, a});
            }
        }
        
        sort(ta.begin(), ta.end()); // |
        sort(tb.begin(), tb.end()); // _

        f(ta, y, m);
        f(tb, x, n);

        cout << ans << '\n';
    }
    return 0;
}