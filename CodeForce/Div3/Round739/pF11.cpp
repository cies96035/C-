#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

set<int> table[2];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i = 0; i < 10; i++){
        for(int j = i; j < 10; j++){
            // cout << i << ' ' << j << endl;
            set<int> t[10];
            t[0].insert(0);
            for(int k = 1; k < 10; k++){
                for(auto p : t[k - 1]){
                    t[k].insert(p * 10 + i);
                    t[k].insert(p * 10 + j);
                }
                for(auto p : t[k]){
                    if(i == j)
                        table[0].insert(p);
                    table[1].insert(p);
                }
            }
        }
    }
    table[0].insert(1111111111);
    table[1].insert(1000000000);
    int t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        if(k == 1){
            cout << *table[0].lower_bound(n) << '\n';
        }else{
            cout << *table[1].lower_bound(n) << '\n';
        }
    }
    
    return 0;
}