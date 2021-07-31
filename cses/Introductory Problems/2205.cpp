#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int n;
vector<string> ans[17];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    ans[0].emplace_back("");
    for(int i = 0; i < n; i++){
        for(auto s : ans[i]){
            ans[i + 1].emplace_back(s + "0");
        }
        for(int j = ans[i].size() - 1; j >= 0; j--){
            ans[i + 1].emplace_back(ans[i][j] + "1");
        }
    }
    for(auto s : ans[n]){
        cout << s << '\n';
    }
    return 0;
}