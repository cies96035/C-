#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < b; i++)
ifstream fin("fraud.in");
ofstream fout("fraud.out");
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
    fin >> re;
    int n;
    vector<string> s;
    fin >> n;
    while(n--){
        fin >> str;
        if(same(re, str)) s.push_back(str);
    }
    fout << s.size() << '\n';
    for(auto st : s){
        fout << st << '\n';
    }
    return 0;
}