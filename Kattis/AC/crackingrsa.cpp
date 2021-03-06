#include<iostream>
using namespace std;
using ll = long long;
const int MAX_N = 1000000;
int factor[MAX_N];
ll T, n, d;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(ll i = 2; i < MAX_N; i++){
        if(!factor[i]){
            for(ll j = i * i; j < MAX_N; j += i){
                factor[j] = i;
            }
            factor[i] = i;
        }
    }

    cin >> T;
    while(T--){
        cin >> n >> d;
        n = (factor[n] - 1) * (n / factor[n] - 1);
        int i = 0;
        while(d * ++i % n != 1);
        cout << i << '\n';
    }
    return 0;
}