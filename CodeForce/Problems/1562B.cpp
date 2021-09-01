#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const char c1[] = {'1', '4', '6', '8', '9'};
vector<char> c2[128];
/*
2 : 2, 5, 7
3 : 2, 3, 5
5 : 2, 5, 7
7 : 2, 5, 7
*/
int t, n;
string str;
void solve(){
    for(auto i : str){
        for(auto j : c1){
            if(i == j){
                cout << 1 << '\n' << i << '\n';
                return;
            }
        }
    }
    bool cnt[256] = {false};
    for(auto i : str){
        for(auto j : c2[i]){
            if(cnt[j]){
                cout << 2 << '\n' << j << i << '\n';
                return;
            }
        }
        cnt[i] = true;
    }
    return;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    c2['2'] = c2['5'] = {'2', '3', '5', '7'};
    c2['3'] = {'3'};
    c2['7'] = {'2', '5', '7'};

    cin >> t;
    while(t--){
        cin >> n >> str;
        solve();
    }
    return 0;
}