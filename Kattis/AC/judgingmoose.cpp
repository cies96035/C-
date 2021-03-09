#include<iostream>
using namespace std;

int l, r;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> l >> r;
    if(l + r == 0){
        cout << "Not a moose\n";
    }else if(l != r){
        cout << "Odd " << max(l, r) * 2 << '\n';
    }else{
        cout << "Even " << l * 2 << '\n';
    }
    return 0;
}