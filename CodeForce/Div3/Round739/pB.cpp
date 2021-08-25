#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t, a, b, c;
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        a--, b--;
        if(a > b){
            swap(a, b);
        }
        int n = (b - a);
        if((b + n) % n == a && a + n == b && c <= 2 * n){
            if(c <= n){
                cout << c + n << '\n';
            }else{
                cout << c - n << '\n';
            }
        }else{
            cout << "-1\n";
        }
    }
    return 0;
}