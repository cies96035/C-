#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 200005;
int n, x;
vector<int> edge[MAX_N];
int sub[MAX_N];
void DFS(int x){
    sub[x] = edge[x].size();
    for(auto i : edge[x]){
        DFS(i);
        sub[x] += sub[i];
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    rep(i, 1, n){
        cin >> x;
        edge[x - 1].emplace_back(i);
    }
    rep(i, 1, n){
        if(!sub[i]){
            DFS(i);
        }
    }
    cout << n - 1;
    rep(i, 1, n){
        cout << ' ' << sub[i];
    }
    cout << '\n';
    
    return 0;
}