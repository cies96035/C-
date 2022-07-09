#include <bits/stdc++.h>
using namespace std;
 
#define int ll
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0)
#define f0r(i, n) for (int i = 0; i < n; ++i)
#define pb emplace_back
#define x first
#define y second
#define all(x) x.begin(), x.end()
 
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vii = vector<pii>;

const int MAX_N = 1e6 + 5;
int t, n;
int a[MAX_N], b[MAX_N];
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        f0r(i, n){
            cin >> a[i];
        }
        f0r(i, n){
            cin >> b[i];
            b[i] -= a[i];
        }
        int cnt = -n + 1;
        f0r(i, n){
            cnt += b[i];
        }
        if(cnt >= 0 && !(n == 2 && b[1] > 0) && !(n != 1 && b[0] == 0)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}