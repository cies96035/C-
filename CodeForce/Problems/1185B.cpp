#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int n;
string s, t;
bool check(){
    if(t.size() < s.size()){
        return false;
    }
    int i = 0;
    for(int j = 0; j < t.size(); j++){
        if(i < s.size() && s[i] == t[j]){
            i++;
        }else if(j == 0 || t[j] != t[j - 1]){
            return false;
        }
    }
    return i == s.size();
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    while(n--){
        cin >> s >> t;
        if(check()){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}