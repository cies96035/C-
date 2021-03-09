#include<iostream>
using namespace std;
using ull = unsigned long long;

const int M = 10000;

char op;
ull a, b;
ull Power(){
    ull base = 1;
    while(b){
        if(b % 2){
            base *= a;
            base %= M;
        }
        b /= 2;
        a *= a;
        a %= M;
    }
    return base;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> a >> op >> b){
        if(op == '+'){
            a += b;
        }else if(op == '*'){
            a *= b;
        }else{
            a = Power();
        }
        cout << a % M << '\n';
    }
    
    return 0;
}