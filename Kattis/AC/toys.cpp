#include<iostream>
using namespace std;

int T, K;
int n;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T >> K;

    n = 0;
    for(int i = 1; i <= T; i++){
        n = (n + K) % i;
    }
    cout << n << '\n';
    return 0;
}