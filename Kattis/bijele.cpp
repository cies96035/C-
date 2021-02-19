#include<iostream>
using namespace std;

int chess;
const int bijele[6] = {1, 1, 2, 2, 2, 8};
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i = 0; i < 5; i++){
        cin >> chess;
        cout << bijele[i] - chess << ' ';
    }
    cin >> chess;
    cout << bijele[5] - chess << '\n';
    return 0;
}