#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)

int n;
vector<pii> ans[17];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    ans[1] = {{1, 3}};
    rep(i, 1, n){
        rep(j, 0, ans[i].size()){
            ans[i + 1].push_back(ans[i][j]);
            if(ans[i + 1].back().first == 3 || ans[i + 1].back().first == 2){
                ans[i + 1].back().first = 5 - ans[i + 1].back().first;
            }
            if(ans[i + 1].back().second == 3 || ans[i + 1].back().second == 2){
                ans[i + 1].back().second = 5 - ans[i + 1].back().second;
            }
        }
        ans[i + 1].push_back({1, 3});
        rep(j, 0, ans[i].size()){
            ans[i + 1].push_back(ans[i][j]);
            if(ans[i + 1].back().first == 1 || ans[i + 1].back().first == 2){
                ans[i + 1].back().first = 3 - ans[i + 1].back().first;
            }
            if(ans[i + 1].back().second == 1 || ans[i + 1].back().second == 2){
                ans[i + 1].back().second = 3 - ans[i + 1].back().second;
            }
        }
    }
    cout << ans[n].size() << '\n';
    for(auto pi : ans[n]){
        cout << pi.first << ' ' << pi.second << '\n';
    }
    return 0;
}