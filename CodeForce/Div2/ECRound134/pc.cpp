#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 5;
int t, n;
int arr[MAX_N], brr[MAX_N];
int ans[MAX_N], bns[MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    arr[0] = 0;
    brr[0] = -1;
    cin >> t;
    while(t--){
        cin >> n;
        rrep(i, 1, n){
            cin >> arr[i];
        }
        rrep(i, 1, n){
            cin >> brr[i];
        }
        int flg = n;
        rvep(i, n, 1){
            if(arr[i] >= brr[i - 1]){
                cout << i << endl;
                rrep(j, i, flg){
                    ans[j] = brr[i] - arr[j];
                    bns[j] = brr[flg] - arr[j];
                }
                flg = i - 1;
            }
        }
        rrep(i, 1, n){
            cout << ans[i] << ' ';
        }cout << '\n';
        rrep(i, 1, n){
            cout << bns[i] << ' ';
        }cout << '\n';
    }
    return 0;
}