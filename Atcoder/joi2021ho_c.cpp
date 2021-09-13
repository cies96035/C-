#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 5e3 + 5;
const int INF = 0x3fffffff;
int n;
int H[MAX_N];
vector<int> s[MAX_N];
int DP[MAX_N]; //[0, i]
void solve(){
    int cnt1, cnt2; // count i, ai < aj, bi > bj
    DP[0] = DP[1] = 0;
    for(int i = 2; i <= n; i++){ // calc [0, i]
        cnt1 = cnt2 = 0;
        DP[i] = INF;
        for(int j = i - 1; j >= 0; j--){ // from [0, j], [j + 1, i]
            cnt1 += (lower_bound(s[j + 1].begin(), s[j + 1].end(), j + 1) - s[j + 1].begin());// 1,2,3,4...
            DP[i] = min(
                DP[j] + cnt1,
                DP[i]
            );
            cout << j + 1 << ' ' << cnt1 << ' ' << cnt2 << endl;
        }
        // for(int j = )
        //     cnt2 += (upper_bound(s[j + 1].begin(), s[j + 1].end(), i) - s[j + 1].begin()) - 1;// 5,4,3,2...
        cout << i << ' ' << DP[i] << endl;
    }
    cout << DP[n] << '\n';
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    rep(i, 0, n){
        cin >> H[i];
    }
    for(int i = n - 1; i >= 0; i--){
        if(i != n - 1)
            s[ H[i] ] = s[ H[i + 1] ];
        s[ H[i] ].emplace_back(H[i]);
        sort(s[ H[i] ].begin(), s[ H[i] ].end());
    }
    rep(i, 1, n){
        for(auto j : s[i]){
            cout << j << ' ';
        }
        cout << endl;
    }
    solve();
    return 0;
}