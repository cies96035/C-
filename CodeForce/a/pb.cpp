#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int n, m, s;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int ipt = 0;
    s = 0;
    cin >> n >> m;
    rep(i, 0, m){
        cin >> ipt;
        s += ipt;
    }
    cout << s % n << '\n';
    return 0;
}