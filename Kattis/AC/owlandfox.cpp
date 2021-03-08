#include<iostream>
using namespace std;

int T, N;
int digitsum[100];
int digits[100010];
int tmp;

inline int getDigitsSum(int x){
    int n = 0;
    while(x){
        n += x % 10;
        x /= 10;
    }
    return n;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i = 0; i <= 100000; i++){
        tmp = getDigitsSum(i);
        digitsum[tmp] = i;
        digits[i] = digitsum[tmp - 1];
    }
    
    cin >> T;
    while(T--){
        cin >> N;
        cout << digits[N] << '\n';
    }
    return 0;
}