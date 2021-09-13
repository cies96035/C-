#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 2e5 + 5;
int n, k[MAX_N], l, ans;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    set<int> s;
    cin >> n;
    l = 0;
    rep(i, 0, n){
        cin >> k[i];
        if(s.count(k[i])){
            while(k[l] != k[i]){
                s.erase(k[l++]);
            }
            l++;
        }else{
            s.insert(k[i]);
            ans = max(ans, (int)s.size());
        }
    }
    cout << ans << '\n';
    return 0;
}