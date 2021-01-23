#include<iostream>
using namespace std;

typedef unsigned long long ull;
ull three_power[39]; //max 3^38
void Init()
{
    three_power[0] = 1;
    for(int i = 1; i < 39; i++)
        three_power[i] = three_power[i - 1] * 3;
    return;
}
void Solve(int n)
{
    n--;
    const string sep = ", ";
    bool HasNumber = 0;
    if(n == 0)
    {
        cout << "{ }\n";
        return;
    }
    cout << "{ ";
    for(int i = 0; n; i++)
    {
        cout<<i<<' '<<n<<endl;
        if(n & 1)
        {
            if(!HasNumber)
                HasNumber = 1;
            else
                cout << sep;
            cout << three_power[i];
        }
        n >>= 1;
    }
    cout << " }\n";
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    Init();
    
    ull t;
    while(cin >> t && t)
        Solve(t);
    return 0;
}