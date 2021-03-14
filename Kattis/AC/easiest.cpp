#include<iostream>
using namespace std;
using ull = unsigned long long;

ull SumOfDigits(ull x){
    ull sum = 0;
    while(x){
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
ull n;
ull nSOD;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> n && n != 0){
        nSOD = SumOfDigits(n);
        for(int i = 11; i <= 100;i++){
            if(nSOD == SumOfDigits(i * n)){
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}