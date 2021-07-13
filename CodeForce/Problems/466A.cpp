#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if(a * m <= b){
        cout << n * a << '\n';
    }else{
        if(n % m * a > b){
            cout << n / m * b + b << '\n';
        }else{
            cout << n / m * b + n % m * a << '\n';
        }
    }
    return 0;
}