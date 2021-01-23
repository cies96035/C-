#include<iostream>
using namespace std;

typedef long long ll;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ll zebra = 0;
    int n;
    char c;
    cin >> n;
    while(n--)
    {
        zebra *= 2;
        cin >> c;
        if(c == 'O')
            zebra++;
    }
    cout << zebra << '\n';
    return 0;
}