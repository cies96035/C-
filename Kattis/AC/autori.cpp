#include<iostream>
using namespace std;

char c;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> c){
        if('A' <= c && c <= 'Z'){
            cout << c;
        }
    }
    cout << '\n';
    return 0;
}