#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    string str;
    cin >> str;
    if( str.find("AB") != -1 && str.find("BA", str.find("AB") + 2) != -1 ||
        str.find("BA") != -1 && str.find("AB", str.find("BA") + 2) != -1
    ){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
    return 0;
}