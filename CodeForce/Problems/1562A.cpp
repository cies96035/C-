#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)
int t;
int l, r;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> l >> r;
        if(l <= r / 2 + 1){
            cout << r % (r / 2 + 1) << '\n';
        }else{
            cout << r % l << '\n';
        }
    }
    return 0;
}