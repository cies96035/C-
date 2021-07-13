#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 200200;

int t;
int n;
ll a[MAX_N];
ll sum;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        sum = 0;
        cin >> n;
        rep(i, 0, n){
            cin >> a[i];
            sum += a[i];
        }
        cout << (sum % n) * (n - sum % n) << '\n';
    }
    return 0;
}