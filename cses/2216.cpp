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
int n;
int ipt;
int cur = 0x3ffffff;
int cnt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    rep(i, 0, n){
        cin >> ipt;
        arr[ipt] = i;
    }
    rrep(i, 1, n){
        if(arr[i] < cur){
            cnt++;
        }
        cur = arr[i];
    }
    cout << cnt << '\n';
    return 0;
}