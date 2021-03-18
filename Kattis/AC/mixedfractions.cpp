#include<iostream>
using namespace std;
using ull = unsigned long long;
ull num, den;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> num >> den && den){
        cout << num / den << ' ' << num % den << " / " << den << '\n';
    }
    return 0;
}