#include<iostream>
using namespace std;

string hey;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> hey;
    cout << 'h';
    for(int i = 4; i < 2 * hey.size(); i++){
        cout << 'e';
    }
    cout << "y\n";
    return 0;
}