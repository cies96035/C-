#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int n;
ll l, r;
ll ans;
bitset<64> num;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    while(n--){
        cin >> l >> r;
        num = l;
        while(num.to_ullong() <= r){
            ans = num.to_ullong();
            for(int i = 0; i < 64; i++){
                if(!num[i]){
                    num[i] = 1;
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}