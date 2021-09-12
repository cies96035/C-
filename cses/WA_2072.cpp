#include<bits/stdc++.h>
#include<ext/rope> //header with rope
using namespace std;
using namespace __gnu_cxx; //namespace with rope and some additional stuff
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    crope str;

    int n, m;
    cin >> n >> m;

    char c;
    rep(i, 0, n){
        cin >> c;
        str.push_back(c);
    }

    int a, b;
    rep(i, 0, 1e5){
        cin >> a >> b;
        a--;
        // str += "AAA"; //).substr(a, b - a);
        // str.erase(a, b - a);
        str = str.substr(0, a) + str.substr(b, str.size() - b) + str.substr(a, b - a);
    }
    cout << str << '\n';
    return 0;
}