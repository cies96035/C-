#include<iostream>
using namespace std;

int n;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    if(n & 1){
        cout << "Bob\n";
    }else{
        cout << "Alice\n";
        cout << n - 1 << '\n';
    }
    return 0;
}