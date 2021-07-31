#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int q;
string s, t;
bool flg;
bool checkl(int i, int j){
    while(i < t.size() && j >= 0){
        // cout << i << ' ' << j << endl;
        if(t[i] != s[j]){
            return false;
        }
        i++, j--;
    }
    return i == t.size();
}
bool checkr(int j){
    int i = 0;
    while(i < t.size() && j < s.size()){
        // cout << i << ' ' << j << endl;
        if(checkl(i, j)){
            return true;
        }
        if(t[i] != s[j]){
            return false;
        }
        i++, j++;
    }
    return i == t.size();
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> q;
    while(q--){
        flg = false;
        cin >> s >> t;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == t[0] && checkr(i)){
                flg = true;
                break;
            }
        }
        if(flg){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}