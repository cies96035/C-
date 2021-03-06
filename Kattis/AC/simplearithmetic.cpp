#include<iostream>
using namespace std;
using ll = long long;

ll a, b, c;
ll floatPoint;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> a >> b >> c;

    cout << a * b / c << '.';
    floatPoint = (a * b % c);
    for(int i = 0; i < 18; i++){
        floatPoint *= 10;
        cout << floatPoint / c;
        floatPoint %= c;
    }
    cout << '\n';
    return 0;
}