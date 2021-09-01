#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t, n;
string str;
void solve(){
    for(int i = 0, m = (n >> 1); i < n; i++){
        if(str[i] == '0'){
            if(i < m){
                cout << i + 1 << ' ' << n << ' ' << i + 2 << ' ' << n << '\n';
            }else{
                cout << 1 << ' ' << i + 1 << ' ' << 1 << ' ' << i << '\n';
            }
            return;
        }
    }
    cout << 1 << ' ' << n - 1 << ' ' << 2 << ' ' << n << '\n';
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n >> str;
        solve();
    }
    return 0;
}