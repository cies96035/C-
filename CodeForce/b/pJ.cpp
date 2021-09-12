#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

struct NODE{
    set<string> child;
    bool b;
    int x;
    NODE(){
        b = false;
    }
};
void DFS(string cur, map<string, NODE> &node, set<pair<int, string>> &ans){
    if(node[cur].b){
        return;
    }
    node[cur].b = true;
    ans.insert({node[cur].x, cur});
    for(auto str : node[cur].child){
        DFS(str, node, ans);
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t;
    int n, k;
    cin >> t;
    while(t--){
        map<string, NODE> node;
        set<pair<int, string>> ans;
        string ipt, ipt2;
        int c;
        cin >> n >> k;
        rep(i, 0, n){
            cin >> ipt >> c;
            node[ipt].x = i;
            rep(j, 0, c){
                cin >> ipt2;
                node[ipt].child.insert(ipt2);
            }
        }
        rep(i, 0, k){
            cin >> ipt;
            DFS(ipt, node, ans);
        }
        for(auto i : ans){
            cout << i.second << '\n';
        }
    }
    return 0;
}