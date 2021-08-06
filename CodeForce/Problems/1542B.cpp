#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t, n, a, b;
bool flg;

/*
((1*a + sb)*a + tb)...
a^k + tb
*/
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        flg = false;
        cin >> n >> a >> b;
        if(a != 1){
            for(ll i = 1; i <= n; i *= a){
                if(!((n - i) % b)){
                    flg = true;
                    break;
                }
            }
        }else{
            flg = !((n - 1) % b);
        }
        if(flg){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
        

    }
    return 0;
}