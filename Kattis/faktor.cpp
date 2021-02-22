#include<iostream>
using namespace std;

int A, I;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> A >> I;
    cout << A * (--I) + 1 << '\n';
    return 0;
}