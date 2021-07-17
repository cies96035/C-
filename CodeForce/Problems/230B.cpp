#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 1000100;
int n;
ll x, xx;
int Prime[100000], Pid;
bool isntPrime[MAX_N];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(ll i = 2; i <= MAX_N; i++){
        if(!isntPrime[i]){
            for(ll j = i * i; j <= MAX_N; j += i){
                isntPrime[j] = true;
            }
            Prime[Pid++] = i;
        }
    }
    cin >> n;
    while(n--){
        cin >> x;
        xx = ll(sqrt(x));
        if( xx * xx == x && *lower_bound(Prime, Prime + Pid, xx) == xx ){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}