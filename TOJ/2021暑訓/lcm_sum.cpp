#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

ll gcd(ll a, ll b){
    while((a%=b)&&(b%=a));
    return a + b;
}
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int T, N = 0;
    cin >> T;
    while(T--){
        cin >> N;
        // ++N;
        ll sum = 0;
        rep(i, 1, N + 1){
            sum += lcm(i, N);
        }
        // cout << setw(3) << N << setw(10) << sum << setw(10) << sum / N << endl;
        cout << sum << '\n';
    }
    return 0;
}