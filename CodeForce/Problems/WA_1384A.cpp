#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

string str[210];
int t, n;
int ipted;
int ipt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    rep(i, 1, 210){
        str[i] = str[i - 1] + 'a';
    }
    
    cin >> t;
    while(t--){
        cin >> n;
        ipted = 0;
        rep(i, 0, n){
            cin >> ipt;
            cout << str[max(ipted, ipt)] << char(i % 2 + 'x') << '\n';
            ipted = ipt;
        }
        cout << str[ipt] << "z\n";
    }
    return 0;
}