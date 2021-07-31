#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t, a, b;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(a < b) swap(a, b);
        if( (a + b) % 3 == 0 && a <= b * 2){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}