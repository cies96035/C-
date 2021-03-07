#include<iostream>
using namespace std;

int n, x;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    while(n--){
        cin >> x;
        if(x & 1){
            cout << x << " is odd\n";
        }else{
            cout << x << " is even\n";
        }
    }
    return 0;
}