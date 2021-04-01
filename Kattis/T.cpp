#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int a, b, M;
    int base = 1;
    cin >> a >> b >> M;
    while(b){
        if(b & 1){
            base = base * a % M;
        }
        a = a * a % M;
        b /= 2;
    }
    cout << base << endl;
    return 0;
}