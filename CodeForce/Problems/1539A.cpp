#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int k;
ll n, x, t;
ll sum;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> k;
    while(k--){
        cin >> n >> x >> t;
        t /= x;
        if(n > t){
            sum = t * (t - 1) / 2 + t * (n - t);
        }else{
            sum = n * (n - 1) / 2;
        }
        cout << sum << '\n';
    }
    return 0;
}