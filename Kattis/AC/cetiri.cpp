#include<iostream>
using namespace std;

int a, b, c;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> a >> b >> c;
    if(a > b){
        swap(a, b);
    }
    if(a > c){
        swap(a, c);
    }
    if(b > c){
        swap(b, c);
    }

    if(b - a == c - b){
        cout << c + b - a << '\n';
    }else if(b - a > c - b){
        cout << a + c - b << '\n';
    }else{
        cout << b + b - a << '\n';
    }
    return 0;
}