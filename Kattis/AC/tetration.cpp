#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
using ld = long double;

ld N;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    cout << fixed << setprecision(6) << pow(N, 1 / N) << '\n';
    return 0;
}