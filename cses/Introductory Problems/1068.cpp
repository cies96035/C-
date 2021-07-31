#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

ll n;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    while(n != 1){
        cout << n << ' ';
        if(n & 1){
            n *= 3;
            n++;
        }else{
            n >>= 1;
        }
    }
    cout << n << '\n';
    return 0;
}