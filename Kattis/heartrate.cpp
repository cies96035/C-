#include<iostream>
#include<iomanip>
using namespace std;
using ld = long double;

int N;
ld b, p;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cout << fixed << setprecision(5);

    cin >> N;
    while(N--){
        cin >> b >> p;
        cout << 60 / p * (b - 1) << ' ' 
        << 60 / p * b << ' ' << 60 / p * (b + 1) << '\n';
    }
    return 0;
}