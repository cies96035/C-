#include<iostream>
using namespace std;

typedef long long ll;
#define M 1000000007
const ll BIGENOUGH = 1LL << 61;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ll t, n, bacteria = 1;
    bool BIG = 0;
    cin >> t;
    while(t--)
    {
        bacteria *= 2;
        cin >> n;
        bacteria -= n;
        if(bacteria >= BIGENOUGH || bacteria <= -BIGENOUGH)
        {
            BIG = 1;
            bacteria %= M;
        }
        else if(!BIG && bacteria < 0)
        {
            cout << "error\n";
            return 0;
        }

    }
    cout << (bacteria % M + M) % M << '\n';
    return 0;
}