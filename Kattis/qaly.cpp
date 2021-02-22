#include<iostream>
using namespace std;
using ld = long double;

int N;
ld q, y, sum;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    while(N--){
        cin >> q >> y;
        sum += q * y;
    }
    cout << sum << '\n';
    return 0;
}