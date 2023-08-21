#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

int n, m;
const int MAX_N = 100 + 5;
const int MAX_M = 10000 + 5;
struct POINT{
    ll x, y;
    bool operator<(const POINT &p) const{
        return p.x != x ? p.x < x : p.y < y;
    }
}p[2][MAX_M];

bool check(){
    rep(j, 0, m){
        if(p[1][j].x != p[0][j].x || p[1][j].y != p[0][j].y ){
            return false;
        }
    }
    return true;
}

ll gcd(ll a, ll b){
    a = abs(a), b = abs(b);
    while((a %= b) && (b %= a));
    return a + b;
}

void Normalize(int i){
    sort(p[i], p[i] + m);

    rvep(j, m - 1, 0){
        p[i][j].x -= p[i][0].x;
        p[i][j].y -= p[i][0].y;
    }
    
    ll d = -1;
    rep(j, 0, m){
        if(p[i][j].x != 0){
            if(d == -1)
                d = abs(p[i][j].x);
            else
                d = gcd(d, p[i][j].x);
        }
        if(p[i][j].y != 0){
            if(d == -1)
                d = abs(p[i][j].y);
            else
                d = gcd(d, p[i][j].y);
        }
    }
    rep(j, 0, m){
        p[i][j].x /= d;
        p[i][j].y /= d;
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    
    rep(i, 0, m){
        cin >> p[0][i].x >> p[0][i].y;
    }
    Normalize(0);

    rrep(i, 1, n){
        rep(j, 0, m){
            cin >> p[1][j].x >> p[1][j].y;
        }
        Normalize(1);
        if(check()){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    
    return 0;
}