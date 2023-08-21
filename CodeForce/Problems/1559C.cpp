#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t, n;
int aed, a;
int ans;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n >> aed;
        if(aed == 1){
            ans = 0;
        }
        rep(i, 1, n){
            cin >> a;
            if(a == 1 && aed == 0){
                ans = i;
            }
            aed = a;
        }
        if(aed == 0){
            ans = n;
        }
        rep(i, 0, n){
            if(ans == i){
                cout << n + 1 << ' ';
            }
            cout << i + 1 << ' ';
        }
        if(ans == n){
            cout << n + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}