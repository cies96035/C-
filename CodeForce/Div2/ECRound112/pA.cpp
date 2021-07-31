#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t;
ll n;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        if(n <= 6){
            cout << 15 << '\n';
        }else{
            cout << (n - 5) / 2 * 5 + 15 << '\n';
        }
    }
    return 0;
}