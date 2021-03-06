#include<iostream>
using namespace std;
using ll = long long;
int P;
int N;
int K;

ll Sum(ll a0, ll d, ll n){

    return (a0 + a0 + d * (n - 1)) * n / 2;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> P;
    while(P--){
        cin >> N >> K;
        cout << N << ' ';
        cout << Sum(1, 1, K) << ' ';
        cout << Sum(1, 2, K) << ' ';
        cout << Sum(2, 2, K) << '\n';
    }
    return 0;
}