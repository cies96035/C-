#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll a, b, T;
ll dsum;
ll precnt(ll x, ll t, const int &digit, const ll &num){
    if(x <= 0){
        return 0;
    }
    if(x % 10 > digit){
        return precnt(x / 10, t * 10, digit, num) + (x / 10 + 1) * t;
    }else if(x % 10 == digit){
        return precnt(x / 10, t * 10, digit, num) + x / 10 * t + num % t + 1;
    }else{
        return precnt(x / 10, t * 10, digit, num) + x / 10 * t ;
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    while(T--){
        cin >> a >> b;
        a--;
        dsum = 0;
        for(ll i = 1; i < 10; i++){
            dsum += ( precnt(b, 1, i, b) - precnt(a, 1, i, a) ) * i;
        }
        cout << dsum << '\n';}

    return 0;
}