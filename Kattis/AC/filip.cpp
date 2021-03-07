#include<iostream>
using namespace std;

string A, B;
int a, b;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> A >> B;
    for(int i = 2; i >= 0; i--){
        a = a * 10 + A[i] - '0';
        b = b * 10 + B[i] - '0';
    }
    cout << max(a, b) << '\n';
    return 0;
}