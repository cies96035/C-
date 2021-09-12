#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int T,x,y;
    cin >> T;
    while(T--){
        cin >> x >> y;
        x = max(x, y);
        cout << x * x << '\n';
    }
    return 0;
}