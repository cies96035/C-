#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
const int MAX_N = 2e5 + 5;
const int INF = 0x3fffffff;
int t, n;
int arr[MAX_N];
string color;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        rep(i, 0, n){
            cin >> arr[i];
        }
        cin >> color;
        vector<int> a, b;
        rep(i, 0, n){
            if(color[i] == 'B'){
                b.pb(i);
            }else{
                a.pb(i);
            }
        }
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end());

        int ia = 0, ib = 0;
        bool flg = true;
        rrep(i, 1, n){
            if(ib < b.size() && b[ib] >= i){
                ib++;
            }else if(ia < a.size() && a[ia] <= i){
                ia++;
            }else{
                flg = false;
                break;
            }
        }
        if(flg){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}