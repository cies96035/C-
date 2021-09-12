#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t;
string str;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        int cnt[26] = {0}, ans = 0, s = 0;
        cin >> str;
        for(auto c : str){
            cnt[c - 'a']++;
        }
        for(auto i : cnt){
            if(i >= 2){
                ans++;
            }else{
                s += i;
            }
        }
        cout << (ans + (s >> 1)) << '\n';
        
    }
    return 0;
}