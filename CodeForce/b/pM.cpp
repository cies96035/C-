#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for(int i = a; i < b; i++)
 
int t, n, s, e, v;
string ipt;
bool check(multiset<pii> &x){
    auto i = x.begin(), j = x.begin();
    j++;
    for(; j != x.end(); i++, j++){
        if(i->second >= j->first){
            return true;
        }
    }
    return false;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        set<string> ans;
        string C;
        map<string, multiset<pii>> dict;
        cin >> n;
        rep(i, 0, n){
            cin >> C >> s >> e;
            cin >> v;
            rep(j, 0, v){
                cin >> ipt;
                dict[ipt].insert({s, e});
            }
        }
        for(auto s : dict){
            // for(auto j : s.second){
            //     cout << j.first << ' ' << j.second << ' ';
            // }
            // cout << endl;
            if(check(s.second)){
                ans.insert(s.first);
            }
        }
        cout << ans.size() << '\n';
        for(auto i : ans){
            cout << i << '\n';
        }
    }
    return 0;
}
/*
lcpc 3 7 4 fegla compo fouad nicole
scpc 3 7 3 fegla fouad nicole
*/