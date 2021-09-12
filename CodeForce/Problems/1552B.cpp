#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 5e4 + 5;
int t;
int n;
int r[MAX_N][5];
bool check(int *a, int *b){
    int cnt = 0;
    rep(i, 0, 5){
        if(a[i] < b[i]){
            cnt++;
        }else{
            cnt--;
        }
    }
    return cnt > 0;
}
void solve(){
    int best[5], ans;
    rep(i, 0, 5){
        best[i] = MAX_N;
    }
    rep(i, 0, n){
        if(check(r[i], best)){
            rep(j, 0, 5){
                best[j] = r[i][j];
            }
            ans = i;
        }
    }
    rep(i, 0, n){
        if(check(r[i], best)){
            cout << "-1\n";
            return;
        }
    }
    cout << ans + 1 << '\n';
    return;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        rep(i, 0, n){
            rep(j, 0, 5){
                cin >> r[i][j];
            }
        }
        solve();
    }
    return 0;
}