#include<iostream>
using namespace std;

int p, q, s;
int gcd(int a, int b){
    while((a %= b) && (b %= a));
    return a + b;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> p >> q >> s;
    
    if(p / gcd(p, q) * q > s){
        cout << "no\n";
    }else{
        cout << "yes\n";
    }
    return 0;
}