#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 110;
int t, n, ipt, sum, cnt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        sum = cnt = 0;
        rep(i, 0, n){
            cin >> ipt;
            sum += ipt;
            cnt += !ipt;
        }
        cout << cnt + (sum + cnt == 0) << '\n';
    }
    return 0;
}