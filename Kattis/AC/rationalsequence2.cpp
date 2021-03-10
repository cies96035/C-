#include<iostream>
using namespace std;
using ull = unsigned long long;

ull P;
ull K, a, b;
char c;
ull rational(ull p, ull q){
    if(p == q){
        return 1;
    }
    if(p > q){
        return rational(p - q, q) * 2 + 1;
    }else{
        return rational(p, q - p) * 2;
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> P;
    while(P--){
        cin >> K >> a >> c >> b;
        cout << K << ' ' << rational(a, b) << '\n';
    }
    
    return 0;
}