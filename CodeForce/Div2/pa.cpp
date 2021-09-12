#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int l, r;
int t;
int n;
string str;
bool solve(){
    for(int i = 1; i < str.size(); i++){
        if(str[i] != str[i - 1]){
            l = i - 1, r = i;
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
        cin >> n >> str;
        if(solve()){
            cout << l + 1 << ' ' << r + 1 << '\n';
        }else{
            cout << -1 << ' ' << -1 << '\n';
        }
    }
    return 0;
}