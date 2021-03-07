#include<iostream>
using namespace std;
using ull = unsigned long long;
ull P, K, b, n;
ull sum;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> P;
    while(P--){
        sum = 0;
        cin >> K >> b >> n;
        while(n){
            sum += (n % b) * (n % b);
            n /= b;
        }
        cout << K << ' ' << sum << '\n';
    }
    return 0;
}