#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const ll INF = 0x7fffffff;
const int MAX_N = 1e5 + 5;

int n;
ll x[MAX_N], y[MAX_N];
ll Mx, My;
ll d;

ll dis(pll a, pll b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}
ll linetrans(ll &a, ll &b){
    ll t = a;
    a += b;
    b = b - t;
}
ll invlinetrans(ll &a, ll &b){
    ll t = b;
    b = (b + a) / 2;
    a = (a - t) / 2;
}
void FindP(){
    ll X[MAX_N], Y[MAX_N];
    rep(i, 0, n){
        X[i] = x[i];
        Y[i] = y[i];
        linetrans(X[i], Y[i]);
    }
    sort(X, X + n);
    sort(Y, Y + n);
    Mx = X[n / 2];
    My = Y[n / 2];

    // cout << Mx << ' ' << My << endl;
    ll l = -1, r = INF, u = -1, d = INF;
    rep(i, 0, n){
        l = max(X[i] - d, l);
        r = min(X[i] + d, r);
        u = max(Y[i] - d, u);
        d = min(Y[i] + d, d);
    }
    // cout << l << ' ' << r << ' ' << u << ' ' << d << endl;
    // FindMean();
    if(l > Mx){
        Mx = l;
    }else if(r < Mx){
        Mx = r;
    }
    if(u > My){
        My = u;
    }else if(d < My){
        My = d;
    }
    invlinetrans(Mx, My);

    return;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    // for(ll i = 0; i < 10; i++){
    //     for(ll j = 0; j < 5; j++){
    //         cout << i << ' ' << j << endl;
    //         linetrans(i, j);
    //         cout << i << ' ' << j << endl;
    //         invlinetrans(i, j);
    //         cout << i << ' ' << j << endl;
    //     }
    // }
    cin >> n;
    rep(i, 0, n){
        cin >> x[i] >> y[i];
    }
    cin >> d;
    FindP();
    // cout << Mx << ' ' << My << endl;
    bool flg = true;
    ll sum = 0;
    rep(i, 0, n){
        ll dist = dis({Mx, My}, {x[i], y[i]});
        if(dist > d){
            flg = false;
        }
        sum += dist;
    }
    if(flg){
        cout << sum <<'\n';
    }else{
        cout << "impossible\n";
    }

    return 0;
}