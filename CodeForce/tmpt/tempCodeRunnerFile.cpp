#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 5;
struct POINTS{
    int type; // 0:l, 1:x, 2:b
    int pos;
    int idx;
    bool operator<(const POINTS x){
        return pos != x.pos ? pos < x.pos: type < x.type;
    }
}points[MAX_N * 3];
int n, pIdx;
ll ans[MAX_N];
void f(){
    pIdx = 0;
    cin >> n;
    int l, a, b, r;
    rep(i, 0, n){
        cin >> l >> a >> b >> r;
        points[pIdx++] = {0, l, 0};
        points[pIdx++] = {2, b, 0};
    }
    int q, x;
    cin >> q;
    rep(i, 0, q){
        cin >> x;
        points[pIdx++] = {1, x, i};
    }
    sort(points, points + pIdx);
    int curSegSize = 0;
    queue<int> curX;
    rep(i, 0, pIdx){
        if(points[i].type == 0) curSegSize++;
        else if(points[i].type == 1){
            if(curSegSize == 0){
                ans[points[i].idx] = points[i].pos;
            }else{
                curX.push(points[i].idx);
            }
        }else if(points[i].type == 2){
            curSegSize--;
            if(curSegSize == 0){
                while(!curX.empty()){
                    ans[curX.front()] = points[i].pos;
                    curX.pop();
                }
            }
        }
    }
    rep(i, 0, q) cout << ans[i] << ' ';
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