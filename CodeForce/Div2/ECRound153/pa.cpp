#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

void f(){
    string str;
    cin >> str;
    if(str == "()"){
        cout << "NO\n";
        return;
    }else{
        string tmp;
        for(auto c:str){
            tmp += "()";
        }
        
        
        // cout << tmp.find(str) << endl;
        if(tmp.find(str) == string::npos){
            cout << "YES\n";
            cout << tmp << '\n';
            return;
        }
        tmp = "";
        for(auto c:str){
            tmp += "(";
        }
        for(auto c:str){
            tmp += ")";
        }
        if(tmp.find(str) == string::npos){
            cout << "YES\n";
            cout << tmp << '\n';
            return;
        }
    }
    cout << "NO\n";
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while(t--) f();
    
    return 0;
}