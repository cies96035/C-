#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 5;
int arr[MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t;
    int n;
    cin >> t;
    while(t--){
        int m1 = 0, m2 = 0;
        cin >> n;
        rep(i, 0, n){
            cin >> arr[i];
            if(arr[i] > m1 && arr[i] > m2){
                m2 = m1;
                m1 = arr[i];
            }else if(arr[i] > m2){
                m2 = arr[i];
            }
        }
        rep(i, 0, n){
            if(arr[i] == m1){
                cout << arr[i] - m2 << ' ';
            }else{
                cout << arr[i] - m1 << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}