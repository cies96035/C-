#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 2e5 + 100;
int t, n, m;
pii ans[MAX_N];
int ansid;
int sp[10], spid;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> t;
    while(t--){
        ansid = 0;
        spid = 0;

        cin >> n;

        for(int i = n - 1, j = sqrt(n); i > 2; i--){
            if(i == j){
                sp[spid++] = j;
                j = sqrt(j);
            }else{
                ans[ansid++] = {i, n};
            }
        }

        m = n;
        rep(i, 0, spid){
            ans[ansid++] = {n, sp[i]};
            ans[ansid++] = {sp[i], n};
            m = (m - 1) / sp[i] + 1;
        }

        while(m > 1){
            ans[ansid++] = pii{n, 2};
            m = (m - 1) / 2 + 1;
        }

        cout << ansid << '\n';
        rep(i, 0, ansid){
            cout << ans[i].first << ' ' << ans[i].second << '\n';
        }
    }
    return 0;
}