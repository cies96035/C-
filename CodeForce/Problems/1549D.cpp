#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 2e5 + 5;
int t, n, ans;
ll aed, a, sptable[MAX_N][20];
ll gcd(ll a, ll b){
    while((a %= b) && (b %= a));
    return a + b;
}
ll rangeGcd(int l, int r){ //[l, r]
    int i = 19;
    while(r - l + 1 < (1 << i)){
        i--;
    }
    return gcd(sptable[l][i], sptable[r - (1 << i) + 1][i]);
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        ans = 0;
        cin >> n >> aed; n--;
        rep(i, 0, n){
            cin >> a;
            sptable[i][0] = abs(a - aed);
            aed = a;
        }

        //sparse table initialize
        for(int i = n - 1; i >= 0; i--){
            for(int j = 1; i + (1 << j) - 1 < n; j++){
                sptable[i][j] = gcd(
                    sptable[i][j - 1] , sptable[i + (1 << (j - 1))][j - 1]
                );
            }
        }

        //find ans
        for(int i = 0, l, r, mid; i < n; i++){
            l = i, r = n;
            while(l < r){ //binary search : begin from i, max range
                mid = (l + r) / 2;
                if(rangeGcd(i, mid) <= 1){
                    r = mid;
                }else{
                    l = mid + 1;
                }
            }
            ans = max(ans, l - i);
        }

        cout << ans + 1 << '\n';
    }
    return 0;
}