#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_NM = 100100;
int n, m;
int Sa[MAX_NM];
int ipt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    rep(i, 0, n){
        cin >> ipt;
        Sa[i + 1] = Sa[i] + ipt;
    }
    cin >> m;
    rep(i, 0, m){
        cin >> ipt;
        cout << lower_bound(Sa, Sa + n, ipt) - Sa << '\n';
    }
    return 0;
}