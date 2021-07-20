#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 1010;
int t;
int n;
int a[MAX_N], b[MAX_N];
ll da, db;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        rep(i, 0, n){
            cin >> a[i] >> b[i];
        }
        sort(a, a + n);
        sort(b, b + n);
        da = a[n / 2] - a[(n - 1) / 2] + 1;
        db = b[n / 2] - b[(n - 1) / 2] + 1;
        cout << da * db << '\n';
    }
    return 0;
}