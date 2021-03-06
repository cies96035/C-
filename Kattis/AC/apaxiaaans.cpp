#include<iostream>
using namespace std;

char c, lc;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    lc = '\0';
    while(cin >> c){
        if(c != lc){
            cout << c;
        }
        lc = c;
    }
    cout << '\n';
    return 0;
}