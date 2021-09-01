#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 1e5 + 5;
int t, n, d;
int a[MAX_N];
int solve(bool x){
    int cnt = 0, odd = !x, even = x;
    rep(i, 0, n){
        if(a[i] & 1){
            if(odd < i){
                cnt += i - odd;
            }
            odd += 2;
        }else{
            if(even < i){
                cnt += i - even;
            }
            even += 2;
        }
    }
    return cnt;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        d = 0;
        rep(i, 0, n){
            cin >> a[i];
            if(a[i] & 1){
                d++;
            }else{
                d--;
            }
        }
        if(d == 1){
            cout << solve(1) << '\n';
        }else if(d == -1){
            cout << solve(0) << '\n';
        }else if(d == 0){
            cout << min(solve(0), solve(1)) << '\n';
        }else{
            cout << "-1\n";
        }
    }
    return 0;
}