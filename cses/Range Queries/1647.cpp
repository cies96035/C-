#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 200005;
int n, q;
int a, b;
int preMin[MAX_N][20];
int t;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> q;
    rep(i, 0, n){
        cin >> preMin[i][0];
    }
    rep(i, 0, 19){
        // cout << i << ":";
        t = 1 << i;
        rep(j, 0, n){
            if(j + t < n){
                preMin[j][i + 1] = min(preMin[j][i], preMin[j + t][i]);
            }else{
                preMin[j][i + 1] = preMin[j][i];
            }
            // cout << preMin[j][i + 1] << ' ';
        }
        // cout << endl;
    }
    while(q--){
        cin >> a >> b;
        a--;
        for(int i = 19; i >= 0; i--){
            t = 1 << i;
            if(b - a >= t){
                cout << min(preMin[b - t][i], preMin[a][i]) << '\n';
                break;
            }
        }
    }
    return 0;
}