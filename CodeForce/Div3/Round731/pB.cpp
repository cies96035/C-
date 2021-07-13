#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

bool check(string str){
    char c = str.size() + 'a' - 1;
    int a = 0, b = str.size() - 1; 
    while(a < b){
        if(str[a] == c){
            a++;
        }else if(str[b] == c){
            b--;
        }else{
            return false;
        }
        c--;
    }
    return str[a] == 'a';
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    string str;
    int t;
    cin >> t;
    while(t--){
        cin >> str;
        if(check(str)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}