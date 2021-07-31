#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_L = 100005;
int q;
string s, t;
bool check(){
    int i = s.size() - 1;
    int j = t.size() - 1;
    while(i >= 0){
        if(s[i] == t.back()){
            break;
        }
        i -= 2;
    }
    if(i < 0){
        return false;
    }
    bool flg = true;
    while(i >= 0){
        if(flg && s[i] == t[j]){
            j--;
        }else{
            flg = !flg;
        }
        if(j < 0){
            return true;
        }
        i--;
    }
    return false;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> q;
    while(q--){
        cin >> s >> t;
        if(check()){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}