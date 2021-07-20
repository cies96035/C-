#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t;
int a[4];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        rep(i, 0, 4){
            cin >> a[i];
        }
        sort(a, a + 4);
        cout << a[0] * a[2] << '\n';
    }
    return 0;
}