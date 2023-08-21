#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < b; i++)
bool same(string a, string b){
    rep(i, 0, a.size()){
        if(a[i] == '*') continue;
        else if(a[i] != b[i]) return false;
    }
    return true;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string re, str;
    cin >> re;
    int n;
    vector<string> s;
    cin >> n;
    while(n--){
        cin >> str;
        if(same(re, str)) s.push_back(str);
    }
    cout << s.size() << '\n';
    for(auto st : s){
        cout << st << '\n';
    }
    return 0;
}