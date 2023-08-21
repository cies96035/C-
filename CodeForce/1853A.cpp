#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 5e2 + 5;
int arr[MAX_N];
void f(){
    int n;
    cin >> n;
    int minVal = 1e9 + 5;
    rep(i, 0, n) {
        cin >> arr[i];
        if(i > 0) minVal = min(minVal, arr[i] - arr[i - 1]);
    }
    cout << max((minVal + 2) / 2, 0) << '\n';
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