#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)
int t, n, a;
string str(55, 'a');
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        cout << str << '\n';
        rep(i, 0, n){
            cin >> a;
            str[a] = 195 - str[a];//'b' - str[a] + 'a'
            cout << str << '\n';
        }
    }
    return 0;
}