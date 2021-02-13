#include<iostream>
using namespace std;
using ll = long long;

const ll M = 1000000007;
const int MAX_SIZE = 50005000;

ll A, B;
ll base, power;
ll ans;
int primeFactor[MAX_SIZE];
// prime -> 0

ll Pow(ll b, ll p){
    ll tmp = 1;
    while(p){
        if(p % 2){
            tmp *= b;
            tmp %= M;
        }
        b *= b;
        b %= M;
        p /= 2;
    }
    return tmp;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(ll i = 2; i < MAX_SIZE; i++){
        if(!primeFactor[i]){
            for(ll j = i * i; j < MAX_SIZE; j += i){
                if(!primeFactor[j])
                    primeFactor[j] = i;
            }
            primeFactor[i] = i;
        }
    }

    cin >> A >> B;
    ans = 1;

    while(A != 1){
        base = primeFactor[A];
        power = 0;
        while(A % base == 0){
            A /= base;
            power++;
        }
        ans *= Pow(base, power * B + 1) - 1;
        ans %= M;
        ans *= Pow(base - 1, M - 2);
        ans %= M;
    }
    cout << ans << '\n';
    return 0;
}