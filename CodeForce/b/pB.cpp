#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)

const int MAX_N = 1e5 + 5;
const ld Unit = 100;
struct NODE{
    int l, r;
    ld x, y;
}node[MAX_N];
int t, n, q, k, leaveX;
int vised[MAX_N], visId = 0;
void DFS(int cur, int d){
    if(cur == -1){
        return;
    }
    DFS(node[cur].l, d + 1);
    DFS(node[cur].r, d + 1);
    
    if(node[cur].l == -1){ //leaves
        node[cur].x = leaveX;
        leaveX += Unit;
    }else{
        node[cur].x = ( node[ node[cur].l ].x + node[ node[cur].r ].x ) / 2.0;
    }
    node[cur].y = d;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cout << fixed << setprecision(4);
    
    cin >> t;
    while(t--){
        visId++;
        leaveX = 0;
        cin >> n >> q;
        int root;
        rrep(i, 1, n){
            cin >> k;
            if(k){
                cin >> node[i].l >> node[i].r;
                vised[ node[i].l ] = vised[ node[i].r ] = visId;
            }else{
                node[i].l = node[i].r = -1;
            }
        }
        rrep(i, 1, n){
            if(vised[i] != visId){
                root = i;
                break;
            }
        }

        DFS(root, 0);

        int r, V, H, U;
        while (q--) {
            cin >> r >> V >> H >> U;
            cout << (node[U].x - node[root].x) / Unit * (H + (r << 1)) << ' ' << -node[U].y * (V + (r << 1)) << endl;
        }
    }
    return 0;
}