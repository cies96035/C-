#include<iostream>
using namespace std;

int a, b, c;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> a >> b >> c;
    if(a + b == c){
        cout << a << '+' << b << '=' << c << '\n';
    }else if(a - b == c){
        cout << a << '-' << b << '=' << c << '\n';
    }else if(a * b == c){
        cout << a << '*' << b << '=' << c << '\n';
    }else if(a % b == 0 && a / b == c){
        cout << a << '/' << b << '=' << c << '\n';
    }else if(a == b + c){
        cout << a << '=' << b << '+' << c << '\n';
    }else if(a == b - c){
        cout << a << '=' << b << '-' << c << '\n';
    }else if(a == b * c){
        cout << a << '=' << b << '*' << c << '\n';
    }else if(b % c == 0 && a == b / c){
        cout << a << '=' << b << '/' << c << '\n';
    }
    return 0;
}