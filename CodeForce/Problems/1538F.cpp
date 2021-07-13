#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int cntDigitChange(int x){
    int cnt = 0;
    while(x){
        cnt += x % 10;
        cnt += x / 10 * 10;
        x /= 10;
    }
    return cnt;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t;
    int l, r;
    cin >> t;
    while(t--){
        cin >> l >> r;
        cout << cntDigitChange(r) - cntDigitChange(l) << '\n';
    }
    return 0;
}