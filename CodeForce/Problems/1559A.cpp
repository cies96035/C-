#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t;
int n, a, num;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        num = -1;
        rep(i, 0, n){
            cin >> a;
            num &= a;
        }
        cout << num << '\n';
    }
    return 0;
}