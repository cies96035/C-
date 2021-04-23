#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 10100;

int T;
int n, m, l;
set<int> e[MAX_N];
int a, b;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    while(T--){
        cin >> n >> m >> l;
        for(int i = 0; i < m; i++){
            cin >> a >> b;
            e[a].insert(b);
        }
        cin >> k;
        
        for(int i = 0; i < n; i++){
            e[i].clear();
        }
    }
    return 0;
}