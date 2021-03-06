#include<iostream>
using namespace std;

int n;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    if(n & 1){
        cout << "Alice\n";
    }else{
        cout << "Bob\n";
    }
    return 0;
}