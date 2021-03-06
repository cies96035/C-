#include<iostream>
using namespace std;
int L, D, X;
int SumOfDigits(int x){
    int sum = 0;
    while(x){
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> L >> D >> X;
    while(SumOfDigits(L) != X){
        L++;
    }
    cout << L << '\n';

    while(SumOfDigits(D) != X){
        D--;
    }
    cout << D << '\n';
    return 0;
}