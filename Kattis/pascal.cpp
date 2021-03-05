#include<iostream>
using namespace std;
using ull = unsigned long long;

ull n;

ull FindMaxFactor(ull x){
    for(ull i = 2; i * i <= x; i++){
        if(x % i == 0){
            return x / i;
        }
    }
    return 1;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    cout << n - FindMaxFactor(n) << '\n';
    return 0;
}