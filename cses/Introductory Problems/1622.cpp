#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

string str;
set<string> ans;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> str;
    sort(str.begin(), str.end());
    do{
        ans.insert(str);
    }while(next_permutation(str.begin(), str.end()));
    cout << ans.size() << '\n';
    for(auto str : ans){
        cout << str << '\n';
    }
    return 0;
}