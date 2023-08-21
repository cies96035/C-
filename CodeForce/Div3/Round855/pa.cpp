#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

char toL(char c){
    if('A' <= c && c <= 'Z')c += 'a' - 'A';
    return c;
}
void f(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    string m;
    m += toL(str[0]);
    rep(i, 1, str.size()){
        if(toL(str[i]) != toL(str[i - 1])){
            m += toL(str[i]);
        }
    }
    if(m == "meow") cout << "YES\n";
    else cout << "NO\n";

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